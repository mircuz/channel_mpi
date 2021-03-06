	/**************************************************************************************************************
	 * 																											  *
	 * 							Header file for the functions used into 2d_fft.c 								  *
	 * 																											  *
	 **************************************************************************************************************
																						Author: Dr. Mirco Meazzo */

#ifndef FFT_SUPPORT_H_
#define FFT_SUPPORT_H_

void print_x_pencil(int nx, int in_klo, FFT_SCALAR *u, int rank, int scounts, int desidered_rank);
void print_y_pencil(int ny, int y_ilo, int y_ihi, int y_klo, 
		FFT_SCALAR *u, int rank, int scounts, int desidered_rank);
void print_z_pencil(int nz, int in_ilo, int in_ihi, FFT_SCALAR *u, int rank, int scounts, int desidered_rank);
void read_data(int nx, int ny, int nz, FFT_SCALAR *U_read, char file_to_read[4]);
void apply_AA(int nx, int ny, int nz, int nxd, int nzd, FFT_SCALAR *U, FFT_SCALAR *U_read);
void z_aliasing(int nx, int nz, int nzd, FFT_SCALAR *U, FFT_SCALAR *U_read);
void x_aliasing(int nx, int nzd,int nxd, FFT_SCALAR *U, FFT_SCALAR *U_read);
void x_dealiasing(int scounts, int nx, int nxd, FFT_SCALAR *u);
void z_dealiasing(int nx, int nz, int nzd, FFT_SCALAR *U);
void cores_handler( int nxd, int nzd, int size, int rank, ptrdiff_t *local_x, ptrdiff_t *local_z, 
							ptrdiff_t *local_x_start, ptrdiff_t *local_z_start);
void block_def(int size, int nxd, int nzd, int *block_x, int *block_z);
void Alltoall(int rank, int size, int in_jlo, int in_jhi, int in_ilo,
					 int in_ihi, int nz, int ny, FFT_SCALAR *arr, FFT_SCALAR *arr_recv, int flag);

#endif /* FFT_SUPPORT_H_ */
