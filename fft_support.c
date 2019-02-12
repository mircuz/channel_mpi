	/******************************************************************************************************
	 * 																									  *
	 * 						Functions developed in order to perform 2D FFT in MPI						  *
	 * 																									  *
	 ******************************************************************************************************
																				 Author: Dr. Mirco Meazzo */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <mpi.h>

typedef double FFT_SCALAR;

/*============================================= Functions Def =============================================*/

void print_array( double *work, int insize, int elem_per_proc, int rank, char string[100] ) {

	//Print work row-wise
	printf("\n\n%s\n"
			"LOCAL array on rank: %d\n", string, rank);
	double re, im;
	int i = 0;
	while ( i < insize*2 ){
		re = work[i];
		i++;
		im = work[i];
		i++;
		printf("%f+i(%f)\t\t", re, im);
		if ( i % (elem_per_proc*2) == 0){
			printf("\n=============\n");
		}
	}
}

void FFT( double *c, int N, int isign ) {
	/**********************************************************************
	  FFT - calculates the discrete fourier transform of an array of double
	  precision complex numbers using the FFT algorithm.

	  c = pointer to an array of size 2*N that contains the real and
	    imaginary parts of the complex numbers. The even numbered indices contain
	    the real parts and the odd numbered indices contain the imaginary parts.
	      c[2*k] = real part of kth data point.
	      c[2*k+1] = imaginary part of kth data point.
	  N = number of data points. The array, c, should contain 2*N elements
	  isign = 1 for forward FFT, -1 for inverse FFT.

	  Copyright (C) 2003, 2004, 2005 Exstrom Laboratories LLC
	*/
  int n, n2, nb, j, k, i0, i1;
  double wr, wi, wrk, wik;
  double d, dr, di, d0r, d0i, d1r, d1i;
  double *cp;

  j = 0;
  n2 = N / 2;
  for( k = 0; k < N; ++k )
  {
    if( k < j )
    {
      i0 = k << 1;
      i1 = j << 1;
      dr = c[i0];
      di = c[i0+1];
      c[i0] = c[i1];
      c[i0+1] = c[i1+1];
      c[i1] = dr;
      c[i1+1] = di;
    }
    n = N >> 1;
    while( (n >= 2) && (j >= n) )
    {
      j -= n;
	  n = n >> 1;
    }
    j += n;
  }

  for( n = 2; n <= N; n = n << 1 )
  {
    wr = cos( 2.0 * M_PI / n );
    wi = sin( 2.0 * M_PI / n );
    if( isign == 1 ) wi = -wi;
    cp = c;
    nb = N / n;
    n2 = n >> 1;
    for( j = 0; j < nb; ++j )
    {
      wrk = 1.0;
      wik = 0.0;
      for( k = 0; k < n2; ++k )
      {
        i0 = k << 1;
        i1 = i0 + n;
        d0r = cp[i0];
        d0i = cp[i0+1];
        d1r = cp[i1];
        d1i = cp[i1+1];
        dr = wrk * d1r - wik * d1i;
        di = wrk * d1i + wik * d1r;
        cp[i0] = d0r + dr;
        cp[i0+1] = d0i + di;
        cp[i1] = d0r - dr;
        cp[i1+1] = d0i - di;
        d = wrk;
        wrk = wr * wrk - wi * wik;
        wik = wr * wik + wi * d;
      }
      cp += n << 1;
    }
  }
}

void b_FFT( double *work, int elem_per_proc, int N_trasf) {

	double* in = (double *) malloc( sizeof(double)*2*N_trasf );
	int count = 0;
	while ( count < elem_per_proc/(2*N_trasf)) {			// To move among rows in the pencil
		// fill IN array
		for ( int i = 0; i < 2*N_trasf; i++ ){
			in[i] = work[i+count*2*N_trasf];
		}
		// Execute FFT & Normalize
		FFT( in, N_trasf, -1 );
		for (int i = 0; i < 2*N_trasf; i++) {
			work[i+count*2*N_trasf] = in[i] / (N_trasf);
		}
		count++;
	}
	free(in);
}

void f_FFT( double *work, int elem_per_proc, int N_trasf) {

	double* in = (double *) malloc( sizeof(double)*2*N_trasf );
	int count = 0;
	while ( count < elem_per_proc/(2*N_trasf)) {			// To move among rows in the pencil
		// fill IN array
		for ( int i = 0; i < 2*N_trasf; i++ ){
			in[i] = work[i+count*2*N_trasf];
		}
		// Execute FFT
		FFT( in, N_trasf, +1 );
		for (int i = 0; i < 2*N_trasf; i++) {
			work[i+count*2*N_trasf] = in[i];
		}
		count++;
	}
	free(in);
}

void check_results( double *work, double *work_ref, int elem_per_proc) {

	/* Remind to add in "Memory Filling" section the following lines od code:
	  FFT_SCALAR *u_ref = (FFT_SCALAR *) malloc(remapsize*sizeof(FFT_SCALAR)*2);
  	  FFT_SCALAR *v_ref = (FFT_SCALAR *) malloc(remapsize*sizeof(FFT_SCALAR)*2);
  	  FFT_SCALAR *w_ref = (FFT_SCALAR *) malloc(remapsize*sizeof(FFT_SCALAR)*2);
  	  MPI_Scatter( U, elem_per_proc , MPI_DOUBLE, u_ref, elem_per_proc,  MPI_DOUBLE, 0, MPI_COMM_WORLD);
  	  MPI_Scatter( V, elem_per_proc , MPI_DOUBLE, v_ref, elem_per_proc,  MPI_DOUBLE, 0, MPI_COMM_WORLD);
  	  MPI_Scatter( W, elem_per_proc , MPI_DOUBLE, w_ref, elem_per_proc,  MPI_DOUBLE, 0, MPI_COMM_WORLD);
 */

	  double mostdiff = 0.0, mydiff= 0.0;
	  for ( int i = 0; i < elem_per_proc; i++) {
		  mydiff = fabs( work[i] - work_ref[i]);
		  if ( mydiff > mostdiff ) {
			  mostdiff = mydiff;
			  printf("Max difference in initial/final values = %.20f\n",mostdiff);
	  	  }
		}
	  //print_array( work_ref, insize, N_trasf, rank, "Reference");
}

void generate_inputs(FFT_SCALAR *U, FFT_SCALAR *V, FFT_SCALAR *W, int nfast, int nmid, int nslow, int rank) {
	//Generate Input
	//int q= 0.0;
	if (rank == 0){
	  for ( int i = 0; i < nslow*nmid*nfast *2; i++) {
		  //U[i] = q++;
		  U[i] = (float)rand()/ (float)(RAND_MAX/10);
	  }
	  for ( int i = 0; i < nslow*nmid*nfast *2; i++) {
		  //V[i] = q++;
		  V[i] = (float)rand()/ (float)(RAND_MAX/10);
	  }
	  for ( int i = 0; i < nslow*nmid*nfast *2; i++) {
		  //W[i] = q++;
		  W[i] = (float)rand()/ (float)(RAND_MAX/10);
	  }
  }

}

void z_aliasing(int nx, int ny, int nz, int nzd, FFT_SCALAR *U, FFT_SCALAR *U_read){
		int nz_left = 1+ (nz-1)/2; 	int reader=0;
	
		for( int stride_x = 0; stride_x < 2*nzd*ny*nx; stride_x = stride_x + 2*nzd*ny) {
			for( int stride_y = 0; stride_y < 2*nzd*ny; stride_y = stride_y + 2*nzd) {
				for (int k= (nzd-nz_left+1)*2; k < nzd*2; k++){
					U[stride_x + stride_y+k] = U_read[reader];
					reader++;
					//printf("U[%d] = %g\n", stride_x + stride_y+k, U[stride_x + stride_y+k]);
				}
				for (int k= (nz_left-1)*2; k < (nzd-nz_left)*2; k++){
					U[stride_x + stride_y+k]=0;
				}
				for (int k= 0; k < (nz_left)*2; k++){
					U[stride_x + stride_y+k] = U_read[reader];
					reader++;
					//printf("U[%d] = %g\n", stride_x + stride_y+k, U[stride_x + stride_y+k]);
				}
		}
	}
}

void x_aliasing(int nx, int ny, int nzd, int nxd, FFT_SCALAR *U, FFT_SCALAR *U_read){
	int reader = nx*ny*nzd*2-1;		//printf("reader %d", reader);
	for( int stride_z = 2*nxd*ny*nzd-1; stride_z > 0 ; stride_z = stride_z - 2*nxd*ny) {			//Backward x evitare sovrascritture
		//printf("stride_z %d\n", stride_z)
		for( int stride_y = 0; stride_y < 2*nxd*ny ; stride_y = stride_y + 2*nxd) {
			//printf("\tstride_y %d\n", stride_y);
			for( int i = 0; i < 2*(nxd-nx); i++) {
				U[stride_z - stride_y - i] = 0;		
				//printf("U0[%d] = %g\n", stride_z - stride_y - i, U[stride_z - stride_y - i]);	
			}
			for( int i = 2*(nxd-nx); i < 2*nxd; i++) {
				U[stride_z - stride_y - i] = U_read[reader];
				//printf("reader %d\n", reader);
				reader--;
				//printf("U[%d] = %g\n", stride_z - stride_y - i, U[stride_z - stride_y - i]);			
			}
		}
	}
}

void x_dealiasing(int scounts, int nx, int nxd, FFT_SCALAR *u) {
	/* scounts = final number of ny*nz modes wanted */
	int stride_x, placeholder=0;
	for (int mode =0; mode < scounts; mode++) {
		stride_x = mode*nxd*2;
		for (int i = 0; i < 2*nx; i++) {
			u[placeholder] = u[stride_x+i];
			placeholder++;
			//printf("u[%d]= %g\n", placeholder, u[placeholder]);
		}
	}
}

void z_dealiasing(int nx, int ny, int nz, int nxd, int nzd, FFT_SCALAR *U) {

	/*for(int i = 0; i < 2*nx*ny*nz; i++) {
			printf("U[%d]= %f\n", i, U[i]);
	}*/

	int nz_left = 1+ (nz-1)/2 ;
	FFT_SCALAR *U_pos = (FFT_SCALAR*)malloc(sizeof(*U_pos) * (2*nx*ny*nz_left));
	memmove(U_pos, U, sizeof(FFT_SCALAR)*2*nx*ny*(1+(nz-1)/2));
	memmove(U, &U[2*nx*ny*(nzd-nz_left+1)], sizeof(FFT_SCALAR)*2*nx*ny*(nz_left-1));
	memmove(&U[2*nx*ny*(nz_left-1)], U_pos, sizeof(FFT_SCALAR)*2*nx*ny*nz_left);
	free(U_pos);
	/*for(int i = 0; i < 2*nx*ny*nz; i++) {
		printf("U[%d]= %f\n", i, U[i]);
	}*/
}

void transpose_on_rank0(int nx, int ny, int nz, FFT_SCALAR *U) {
	/* This routine remap the array in such a manner that negative modes appears on the left side
	 * of the array. Once remap is completed, the array is transposed in y pencil */
	struct cmplx {
		double re, im;
	};

	int reader = 0, writer = 0;
	// Fill the array on rank 0
	struct cmplx u_mat[nx][ny];
	for (int k = 0; k < nz; k++) {

		// Read the k-th plane
		for (int j = 0; j < ny; j++) {
			for (int i = 0; i < nx; i++) {
				//printf("U[%d] = %g\n", reader, U[reader]);
				u_mat[i][j].re = U[reader];
				reader++;
				//printf("U[%d] = %g\n", reader, U[reader]);
				u_mat[i][j].im = U[reader];
				reader++;
			}
		}
		// Transpose the k-th plane
		for (int i = 0; i < nx; i++) {
			for (int j = 0; j < ny; j++) {
				U[writer] = u_mat[i][j].re;
				//printf("U[%d] = %g\n", writer, U[writer]);
				writer++;
				U[writer] = u_mat[i][j].im;
				//printf("U[%d] = %g\n", writer, U[writer]);
				writer++;
			}
		}
	}
}

void cores_handler( int modes, int size, int *modes_per_proc) {
	int rank =0;
	int check=0;

	for (int i = 0; i < modes; i++) {
		modes_per_proc[rank] = modes_per_proc[rank]+1;
		rank = rank+1;
		if (rank == size ) rank = 0;
	}
	
	for (int i = 0; i < size; i++){
		//printf("%d modes on rank %d\n", modes_per_proc[i], i);
		check = check+modes_per_proc[i];
	}
	if ( (int)(check - modes) != 0 ) {
			printf("[ERROR] check - modes = %d!!\nUnable to scatter modes properly\nAbort... \n", check - modes);
	}


}

void read_data(int nx, int ny, int nz, FFT_SCALAR *U_read, char file_to_read[4]) {
	//On rank 0 read the dataset
	FILE *U_dat;	U_dat = fopen( file_to_read, "r");
	for ( int i = 0; i < (nx)*(ny)*(nz)*2; i++) {
		fscanf( U_dat, "%lf", &U_read[i]);
		//printf("I've read %lf\n", U_read[i]);
	}
}

/* APPLY GLOBAL AA Z PENCIL VERSION */
void print_z_pencil(int nz, int in_ilo, int in_ihi, int in_jlo,
		FFT_SCALAR *u, int rank, int scounts, int desidered_rank);
void apply_AA(int nx, int ny, int nz, int nxd, int nzd, FFT_SCALAR *U, FFT_SCALAR *U_read){
	int nz_left = 1+ (nz-1)/2; 	int reader=0;
	// z-AA
	for( int stride_y = 0; stride_y < 2*nzd*nxd*ny; stride_y = stride_y + 2*nzd*nxd) {
		for( int stride_x = 0; stride_x < 2*nzd*nx; stride_x = stride_x + 2*nzd) {
			for (int k= (nzd-nz_left+1)*2; k < nzd*2; k++){
				U[stride_x + stride_y+k] = U_read[reader];
				reader++;
			}
			for (int k= (nz_left-1)*2; k < (nzd-nz_left)*2; k++){
				U[stride_x + stride_y+k]=0;
			}
			for (int k= 0; k < (nz_left)*2; k++){
				U[stride_x + stride_y+k] = U_read[reader];
				reader++;
			}
		}
		for (int stride_x = 2*nzd*nx; stride_x < 2*nzd*nxd; stride_x = stride_x + 2*nzd*nxd) {
			for (int k= 0; k < nzd*2; k++){		
				U[stride_x + stride_y+k]=0;
			}
		}
	}
	//print_z_pencil(nzd, 0, nxd-1, 0, U, 0, 2*nxd*ny*nzd, 0);
}

/*	APPLY GLOBAL AA X-PENCIL VERSION 
void apply_AA(int nx, int ny, int nz, int nxd, int nzd, FFT_SCALAR *U, FFT_SCALAR *U_read) {
	int nz_left = 1+ (nz-1)/2, reader= 2*nx*ny*(nz_left-1) ;
	  	  //Fill the array with read values and zeros for AA
	int i, stride_y, stride_z, last_index;
	for ( stride_z = 0; stride_z < nz_left*ny*nxd*2; stride_z = stride_z + ny*nxd*2) {
		//printf("\n\nstride z %d\n", stride_z );
		for ( stride_y = 0; stride_y < ny*nxd*2; stride_y = stride_y + nxd*2) {
			//printf("\nstride y %d\n", stride_y );
			for ( i = 0; i < (nx)*2; i++) {
				U[stride_z + stride_y+i] = U_read[reader];
				//printf("U[%d] =  %g\n", (stride_z + stride_y+i), U[stride_z + stride_y+i]);
				reader++;
			}
			for ( i = (nx)*2; i < nxd*2; i++) {
				U[stride_z + stride_y+i] = 0;
				// printf("U[%d] =  %g\n", (stride_z + stride_y+i), U[stride_z + stride_y+i]);
			}
		}
		last_index = stride_z + stride_y;
		//printf("last %d\n", (nzd - nz_left+1)*nxd*ny*2);
	}
	//Fill with zeros from nz to nzd
	for ( int i = last_index; i < (nzd - nz_left+1)*nxd*ny*2; i++) {
		U[i] = 0;
	}
	reader= 0;
	for ( stride_z = (nzd - nz_left+1)*nxd*ny*2; stride_z < nzd*ny*nxd*2; stride_z = stride_z + ny*nxd*2) {
		//printf("\n\nstride z %d\n", stride_z );
		for ( stride_y = 0 ; stride_y < ny*nxd*2; stride_y = stride_y + nxd*2) {
			//printf("\nstride y %d\n", stride_y );
			for ( i = 0; i < (nx)*2; i++) {
				U[stride_z + stride_y+i] = U_read[reader];
				//printf("U[%d] =  %g\n", (stride_z + stride_y+i), U[stride_z + stride_y+i]);
				reader++;
			}
			for ( i = (nx)*2; i < nxd*2; i++) {
				U[stride_z + stride_y+i] = 0;
				//printf("U[%d] =  %g\n", (stride_z + stride_y+i), U[stride_z + stride_y+i]);
			}
		}
		last_index = stride_z + stride_y;
		//printf("last %d\n", last_index);
	}
	 for (int i =0; i < nxd*nzd*ny*2; i++) {
	  		  printf("u[%d] = %g\n", i, U[i]);
	  	  } 
}*/

void print_x_pencil(int nx, int in_jlo, int in_jhi, int in_klo,
		FFT_SCALAR *u, int rank, int scounts, int desidered_rank) {
if (rank == desidered_rank) {
	  int stride_nz = in_klo;
	  int stride_ny = in_jlo;

	  for (int i = 0; i < scounts; i++) {
   	  if ( i % (nx*2) == 0) {
   		  printf("========(ny= %d, nz= %d)=======\n", stride_ny , stride_nz);
   		  if ( (stride_ny ) == in_jhi) {
   			  stride_ny = in_jlo;
   			  stride_nz ++;
   		  }
   		  else stride_ny ++;
   	  }
   	  printf("u[%d]= %.10f\n", (i), u[i]);
	  }
}
}

void print_y_pencil(int nx, int ny, int nz, FFT_SCALAR *u, int rank,
		int displs, int scounts, int desidered_rank) {
if (rank == desidered_rank) {
	  int total_modes = displs/ (ny*2);
	  int stride_nz = total_modes / nx;
	  int stride_nx = total_modes - stride_nz * nx;

	  for (int i = 0; i < scounts; i++) {
   	  if ( i % (ny*2) == 0) {
   		  printf("========(nx= %d, nz= %d)=======\n", stride_nx , stride_nz);
   		  if ( (stride_nx ) == (nx-1)) {
   			  stride_nx =0;
   			  stride_nz ++;
   		  }
   		  else stride_nx++;
   	  }
   	 printf("u[%d]= %.10f\n", (i), u[i]);
     }
 }
}

void print_z_pencil(int nz, int in_ilo, int in_ihi, int in_jlo,
		FFT_SCALAR *u, int rank, int scounts, int desidered_rank) {
if (rank == desidered_rank) {
	int stride_nx = in_ilo;
	int stride_ny = in_jlo;

	for (int i = 0; i < scounts; i++) {
		if ( i % (nz*2) == 0) {
			printf("========(nx= %d, ny= %d)=======\n", stride_nx , stride_ny);
			if ( (stride_nx) == in_ihi) {
				stride_nx = in_ilo;
				stride_ny++;
			}
			else stride_nx ++;
		}
		printf("u[%d]= %.10f\n", (i), u[i]);
	}
}
}

void Alltoall(int rank, int size, int in_jlo, int in_jhi, int in_ilo,
					 int in_ihi, int nz, int nx, FFT_SCALAR *arr, FFT_SCALAR *arr_recv, int flag){
	/* Flag = 1 	=> 	Scatterw
	 * Flag = -1 	=>	Gatherw */

	int *contiguous_x = (int *) malloc(sizeof(int)*size);
	int *contiguous_y = (int *) malloc(sizeof(int)*size);
	int *sendcounts = (int *) malloc(sizeof(int)*size);
	int *senddispls = (int *) malloc(sizeof(int)*size);
	int *recvdispls = (int *) malloc(sizeof(int)*size);
	int *recvcounts = (int *) malloc(sizeof(int)*size);
	if (( contiguous_x||contiguous_y||senddispls||sendcounts||recvdispls||recvcounts ) == NULL) {
		perror(".:Error while allocating memory for Alltoallw parameters:.\n");
		abort();
	}
	MPI_Datatype recvtype[size];
	contiguous_y[rank] = (in_jhi-in_jlo+1);
	contiguous_x[rank] = (in_ihi-in_ilo+1);
	for (int i = 0; i < size; i++){
		sendcounts[i] = 0;	recvdispls[i] = 0;		recvcounts[i] = 0;		recvtype[i] = MPI_DOUBLE;
	}
	// Broadcaster is the only one who send something
	if (rank == 0) {
		for (int i  = 0; i < size; i++){
			sendcounts[i] = 1;
		}
	}
	senddispls[rank] = (2*nz*in_ilo + 2*nz*nx*in_jlo )*sizeof(double);
	recvcounts[0] = 2*nz*(in_jhi-in_jlo+1)*(in_ihi-in_ilo+1);
	//printf("RECV COUNTS %d\n", recvcounts[0]);
	MPI_Allgather(&contiguous_y[rank],1,MPI_INT,contiguous_y,1,MPI_INT, MPI_COMM_WORLD);
	MPI_Allgather(&contiguous_x[rank],1,MPI_INT,contiguous_x,1,MPI_INT, MPI_COMM_WORLD);
	MPI_Allgather(&senddispls[rank],1,MPI_INT,senddispls,1,MPI_INT, MPI_COMM_WORLD);

	MPI_Datatype vector[size], contiguous[size];
	int bytes_stride = sizeof(double)*2*nz*nx;

	for (int i = 0; i < size; i++) {
		MPI_Type_contiguous(2*nz*contiguous_x[i], MPI_DOUBLE, &contiguous[i]);
		MPI_Type_create_hvector(contiguous_y[i], 1, bytes_stride, contiguous[i], &vector[i]);
		MPI_Type_commit(&vector[i]);
	}

	if (flag == 1) {
		MPI_Alltoallw(&arr[0], sendcounts, senddispls, vector, &arr_recv[0], recvcounts, recvdispls, recvtype, MPI_COMM_WORLD);
	}
	else if (flag == -1) {
		MPI_Alltoallw(&arr_recv[0], recvcounts, recvdispls, recvtype, &arr[0], sendcounts, senddispls, vector, MPI_COMM_WORLD);
	}
	else {
		perror(".:Invalid FLAG for Alltoall call:.\n\n");
		abort();
	}
	/*/Checking function
	if (rank == 3){
		  for(int i = 0; i < recvcounts[0]; i++){
			  printf("arr_recv[%d]= %f\n", i, arr_recv[i]);
		  }
	  }
	*/
	MPI_Type_free(vector);
}

