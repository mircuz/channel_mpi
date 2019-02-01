	/**************************************************************************************************************
	 * 																											  *
	 * 							Header file for the functions used into 2d_fft.c 								  *
	 * 																											  *
	 **************************************************************************************************************
																						Author: Dr. Mirco Meazzo */

#ifndef FFT_SUPPORT_H_
#define FFT_SUPPORT_H_


void print_array( double *work, int insize, int elem_per_proc, int rank, char string[100] );
void print_x_pencil(int nx, int in_jlo, int in_jhi, int in_klo,
		FFT_SCALAR *u, int rank, int scounts, int desidered_rank);
void print_y_pencil(int nx, int ny, int nz, FFT_SCALAR *u, int rank,
		int displs, int scounts, int desidered_rank);
void print_z_pencil(int nz, int in_ilo, int in_ihi, int in_jlo,
		FFT_SCALAR *u, int rank, int scounts, int desidered_rank);
void FFT( double *c, int N, int isign );
void b_FFT( double *work, int elem_per_proc, int N_trasf);
void f_FFT( double *work, int elem_per_proc, int N_trasf);
void read_data(int nx, int ny, int nz, FFT_SCALAR *U_read, char file_to_read[4]);
void apply_AA(int nx, int ny, int nz, int nxd, int nzd, FFT_SCALAR *U, FFT_SCALAR *U_read);
void x_dealiasing(int scounts, int modes_per_proc, int nx, int nxd, FFT_SCALAR *u);
void z_dealiasing(int nx, int ny, int nz, int nxd, int nzd, FFT_SCALAR *U);
void transpose_on_rank0(int nx, int ny, int nz, FFT_SCALAR *U);
void cores_handler( int modes, int size, int *modes_per_proc);
void Alltoall(int rank, int size, int in_jlo, int in_jhi, int in_klo,
					 int in_khi, int nxd, int ny, int nzd, FFT_SCALAR *arr, FFT_SCALAR *arr_recv, int flag);

// No longer in use
void check_results( double *work, double *work_ref, int elem_per_proc);
void generate_inputs(FFT_SCALAR *U, FFT_SCALAR *V, FFT_SCALAR *W, int nfast, int nmid, int nslow, int rank) ;

#endif /* FFT_SUPPORT_H_ */
