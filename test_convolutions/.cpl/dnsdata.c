/**/
#define _GNU_SOURCE

#define _FILE_OFFSET_BITS 64

#define _LARGE_FILES

#define printERR fprintf(stderr,"\r%s: PROGRAM HALTED  \n",errormessage);fflush(stderr)


#include <unistd.h>

#include <stdlib.h>
/*** struct __pthread_mutex_s
 {
 int __lock;
 unsigned int __count;
 int __owner;
unsigned int __nusers;
int __kind;
short __spins;
 short __elision;
 __pthread_list_t __list;
} __data ununderstood ***/

#include <stdio.h>

#include <fcntl.h>

#include <math.h>

#include <limits.h>

#include <float.h>

#include <string.h>


#include <sys/time.h>

#include <sys/types.h>

#include <setjmp.h>

#include <errno.h>

#include <signal.h>
#if defined nofenv
  #define feenableexcept(fpe)
  #define feclearexcept(fpe)
#else
  #include <fenv.h>
  #define fpe FE_INVALID | FE_OVERFLOW | FE_DIVBYZERO
#endif

extern char errortemp_[(80+1)];
struct arrptr{int l,h; ssize_t i; char *a;};struct dynptr{void* p; int t;};extern char INTERRUPT;extern void (*traphandler)(const char *);struct freefunc{struct freefunc *next; void (*f)(void *); void *ptr;};extern struct freefunc *freestack;
#define freemem(upto) while(freestack!=upto){freestack->f(freestack->ptr); freestack=freestack->next;}

#define atblockexit(name,func,p) name.f=func;name.ptr=p;name.next=freestack;freestack=&name

#define mmovefrom(var,buf,type) *(type *)(buf)=*var

#define mmoveto(var,buf,type) *var=*(type *)(buf)

#define mainstart void default_traphandler(const char *errormessage){   freemem(NULL);   if(errormessage[0]){     printERR;     exit(EXIT_FAILURE);   }else exit(EXIT_SUCCESS); } int main(int argc, char **argv){ struct freefunc* es; {void (*sig)(int); if((sig=signal(SIGSEGV,trapsignal))!=SIG_DFL)signal(SIGSEGV,sig); if((sig=signal(SIGFPE,trapsignal))!=SIG_DFL)signal(SIGFPE,sig); if((sig=signal(SIGILL,trapsignal))!=SIG_DFL)signal(SIGILL,sig); if((sig=signal(SIGINT,trapsignal))!=SIG_DFL)signal(SIGINT,sig); else {traphandler=default_traphandler;       freestack=NULL;       feenableexcept(fpe);      }; } es=freestack;
extern void traprestore(void *ptr);extern void condfree(void *ptr);extern int dynptrerr(int type);extern void *errmalloc();extern void ioerr(FILE *fil);extern void errfclose(void *voidf);extern void errfopen(FILE **f, const char *name, int mode);extern int scanrec(FILE *f, const char *format, void *var) ;extern int myfgets(char *name, char *var, char *varend, FILE *f) ;extern int mygetline(char *name, char **var, FILE *f) ;extern void trapsignal(int signum);

/*!USE rtchecks*/
/*!#define bodyforce*/
/*!#define scalar*/
/*gamma=0*/
/*!USE rtchecks*/
struct COMPLEX_{double REAL_;double IMAG_;};void complex_1INV(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_2EXP(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_3SINH(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_4COSH(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_5TANH(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_6COTH(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_7LOG(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_8POWER(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG,double y_REAL,double y_IMAG);
void complex_9SQRT(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_10ACOS(struct COMPLEX_ *RESULT_,double x_REAL,double x_IMAG);
void complex_11CRAND(struct COMPLEX_ *RESULT_);
void complex_12CGAUSS(struct COMPLEX_ *RESULT_);

void fft_1IFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_2FFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_3RFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_4HFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_5IFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_6FFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_7RFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_8HFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);

int fft_9FFTfit(int N_);
void fft_fft_10ReverseInc(int *K_,int N_);
extern int fft_fft_LASTN;
extern struct arrptr fft_fft_CEXP;
extern struct arrptr fft_fft_tempVEC;
extern struct arrptr fft_fft_RI;
extern char *fft_fft_RI2;
extern char *fft_fft_RI3;
void fft_fft_11SETUP(int N_);
extern double fft_fft_12C3;
/*C3=fft_fft_12C3*/
void fft_fft_13BTFLY(int N_,int M_);
void fft_fft_14BTFLYI(int N_);
void fft_1IFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_2FFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_3RFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_4HFT(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_5IFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_6FFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_7RFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
void fft_8HFTU(const int Rin_l,const int Rin_h,const ssize_t Rin_i,char *Rin__,const int Rout_l,const int Rout_h,const ssize_t Rout_i,char *Rout__);
double *fft_15REALIFIED(const int x_l,const int x_h,const ssize_t x_i,char *x__,int y_);

double DotProduct(const int a_l,const int a_h,const ssize_t a_i,char *a__,const int b_l,const int b_h,const ssize_t b_i,char *b__);
void rbmat_1LeftMult(const int c_l,const int c_h,const ssize_t c_i,char *c__,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,char *A___,const int b_l,const int b_h,const ssize_t b_i,char *b__);
void RightMult(const int c_l,const int c_h,const ssize_t c_i,char *c__,const int a_l,const int a_h,const ssize_t a_i,char *a__,const int B_l,const int B_h,const ssize_t B_i,const int B__l,const int B__h,const ssize_t B__i,char *B___);
struct REALINVMAT_{int lo_;int hi_;};void rbmat_2MatEqu(const int c_l,const int c_h,const ssize_t c_i,const int c__l,const int c__h,const ssize_t c__i,char *c___,double a_);
void rbmat_3MatEqu(FILE *c_f,const int c_l,const int c_h,const ssize_t c_i,const int c__l,const int c__h,const ssize_t c__i,off_t c___,double a_);
void rbmat_4LeftMult(const int c_l,const int c_h,const ssize_t c_i,char *c__,FILE *A_f,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,off_t A___,const int b_l,const int b_h,const ssize_t b_i,char *b__);
void rbmat_5RightMult(const int c_l,const int c_h,const ssize_t c_i,char *c__,const int a_l,const int a_h,const ssize_t a_i,char *a__,FILE *B_f,const int B_l,const int B_h,const ssize_t B_i,const int B__l,const int B__h,const ssize_t B__i,off_t B___);
void rbmat_6LUdecomp(const int AA_l,const int AA_h,const ssize_t AA_i,const int AA__l,const int AA__h,const ssize_t AA__i,char *AA___);
void rbmat_7LUdecomp(FILE *A_f,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,off_t A___);
void rbmat_8LeftLDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,char *A___,const int t_l,const int t_h,const ssize_t t_i,char *t__);
void rbmat_9LeftUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,char *A___,const int t_l,const int t_h,const ssize_t t_i,char *t__);
void rbmat_10LeftLUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,FILE *A_f,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,off_t A___,const int t_l,const int t_h,const ssize_t t_i,char *t__);
void rbmat_11RightLUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int t_l,const int t_h,const ssize_t t_i,char *t__,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,char *A___);
void rbmat_12RightLUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int t_l,const int t_h,const ssize_t t_i,char *t__,FILE *A_f,const int A_l,const int A_h,const ssize_t A_i,const int A__l,const int A__h,const ssize_t A__i,off_t A___);
extern double Lanczos_norm_;
void rbmat_13Lanczos(const int x_l,const int x_h,const ssize_t x_i,char *x__,void (*A_)(const int v2_l,const int v2_h,const ssize_t v2_i,char *v2__,const int v1_l,const int v1_h,const ssize_t v1_i,char *v1__),void (*B_)(const int v2_l,const int v2_h,const ssize_t v2_i,char *v2__,const int v1_l,const int v1_h,const ssize_t v1_i,char *v1__),const int y1_l,const int y1_h,const ssize_t y1_i,char *y1__,double eps_);
void rbmat_14PLU(const int m_l,const int m_h,const ssize_t m_i,const int m__l,const int m__h,const ssize_t m__i,char *m___,struct REALINVMAT_ *RESULT_);
void rbmat_15LeftLUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,struct REALINVMAT_ *m_,const int t_l,const int t_h,const ssize_t t_i,char *t__);
void rbmat_16RightLUDiv(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int t_l,const int t_h,const ssize_t t_i,char *t__,struct REALINVMAT_ *m_);
void rbmat_17INV(const int mat_l,const int mat_h,const ssize_t mat_i,const int mat__l,const int mat__h,const ssize_t mat__i,char *mat___,const int RESULT_l,const int RESULT_h,const ssize_t RESULT_i,const int RESULT__l,const int RESULT__h,const ssize_t RESULT__i,char *RESULT___);
double rbmat_18DET(const int mat_l,const int mat_h,const ssize_t mat_i,const int mat__l,const int mat__h,const ssize_t mat__i,char *mat___);
void rbmat_19Lanczos(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int mat_l,const int mat_h,const ssize_t mat_i,const int mat__l,const int mat__h,const ssize_t mat__i,char *mat___,const int y_l,const int y_h,const ssize_t y_i,char *y__,double eps_);

struct rbmat_Lanczos_R_s20 {int l,h; ssize_t i;struct arrptr a;};
extern struct rbmat_Lanczos_R_s20 rbmat_Lanczos_R_Lanczos_mat;
void rbmat_Lanczos_R_21A(const int v2_l,const int v2_h,const ssize_t v2_i,char *v2__,const int v1_l,const int v1_h,const ssize_t v1_i,char *v1__);
void rbmat_Lanczos_R_22B(const int v2_l,const int v2_h,const ssize_t v2_i,char *v2__,const int v1_l,const int v1_h,const ssize_t v1_i,char *v1__);
void rbmat_19Lanczos(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int mat_l,const int mat_h,const ssize_t mat_i,const int mat__l,const int mat__h,const ssize_t mat__i,char *mat___,const int y_l,const int y_h,const ssize_t y_i,char *y__,double eps_);


#include <sys/mman.h>

#include <sys/wait.h>

#include <sys/shm.h>


#define SHMPAGE 4194304
extern size_t shmavail;extern char *shmaddr;extern void *shmalloc(size_t size);extern sigset_t oldmask;extern void donothing(int signum);extern void setup_signal_USR1();


#include <sys/socket.h>

#include <netinet/in.h>
/*** typedef uint32_t in_addr_t; ununderstood ***/
/*** in_addr_t s_addr ununderstood ***/
/*** typedef uint16_t in_port_t; ununderstood ***/
/*** uint8_t	__u6_addr8[16] ununderstood ***/
/*** uint16_t __u6_addr16[8] ununderstood ***/
/*** uint32_t __u6_addr32[4] ununderstood ***/
/*** in_port_t sin_port ununderstood ***/
/*** in_port_t sin6_port ununderstood ***/
/*** uint32_t sin6_flowinfo ununderstood ***/
/*** uint32_t sin6_scope_id ununderstood ***/
/*** uint32_t gr_interface ununderstood ***/
/*** uint32_t gsr_interface ununderstood ***/
/*** uint32_t imsf_fmode ununderstood ***/
/*** uint32_t imsf_numsrc ununderstood ***/
/*** uint32_t gf_interface ununderstood ***/
/*** uint32_t gf_fmode ununderstood ***/
/*** uint32_t gf_numsrc ununderstood ***/
/*** extern uint32_t ntohl (uint32_t __netlong)  __attribute__ ((__const__)); ununderstood ***/
/*** extern uint16_t ntohs (uint16_t __netshort) ununderstood ***/
/*** __attribute__ ((__const__)); ununderstood ***/
/*** extern uint32_t htonl (uint32_t __hostlong) ununderstood ***/
/*** __attribute__ ((__const__)); ununderstood ***/
/*** extern uint16_t htons (uint16_t __hostshort) ununderstood ***/
/*** __attribute__ ((__const__)); ununderstood ***/
/*** uint32_t ip6m_mtu ununderstood ***/
/*** extern uint8_t *inet6_option_alloc (struct cmsghdr *__cmsg, int __datalen,
				 int __multx, int __plusy) ununderstood ***/

#include <netinet/tcp.h>
/*** # error "Adjust your <bits/endian.h> defines"
u_int16_t window ununderstood ***/
/*** enum ununderstood ***/
/*** {
 TCP_NO_QUEUE,
 TCP_RECV_QUEUE,
 TCP_SEND_QUEUE,
 TCP_QUEUES_NR,
}; ununderstood ***/

#include <netdb.h>
/*** uint32_t n_net ununderstood ***/
extern int tcpserver(uint16_t port)
;extern int tcpclient(const char *hostname, uint16_t port) 
;extern int udpsocket(uint16_t myport, const char *hostname, uint16_t hostport) 
;

void barrier_free(void * ptr);
extern struct freefunc barrier_f;extern volatile int *barrier_;


/**/
/*nsmp=1*/


/*! Parallel - initialization*/
int iproc_;
int nproc_;

/*bufsize=800*/
  /*baseport=(IPPORT_USERRESERVED+111)*/

struct freefunc prev_f;FILE *prev_;
struct freefunc next_f;FILE *next_;

    


void rbmatmod_1LUdecompStep(const int A_l,const int A_h,const ssize_t A_i,char *A__);
void rbmatmod_2LeftLUDivStep1(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int A_l,const int A_h,const ssize_t A_i,char *A__,const int t_l,const int t_h,const ssize_t t_i,char *t__);
void rbmatmod_3LeftLUDivStep2(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int A_l,const int A_h,const ssize_t A_i,char *A__);
void rbmatmod_4RightLUDivStep1(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int t_l,const int t_h,const ssize_t t_i,char *t__,const int A_l,const int A_h,const ssize_t A_i,char *A__);
void rbmatmod_5RightLUDivStep2(const int x_l,const int x_h,const ssize_t x_i,char *x__,const int A_l,const int A_h,const ssize_t A_i,char *A__);
int ny_;
int nx_;
int nz_;

double alfa0_;
double beta0_;
double a_;
double ymin_;
double ymax_;
double t_max_;
double dt_field_;
double dt_save_;

double u_conv_;
double u0_;
double un_;
double w_conv_;
double w0_;
double wn_;
double t0_;
double tn_;

double ni_;
double pr_;
double meanpx_;
double meanpz_;
double meanflowx_;
double meanflowz_;
double px_;
double corrpx_;
double pz_;
double corrpz_;
double flowx_;
double flowz_;
double deltat_;
double cflmax_;
double time_;

int time_from_restart_;

struct freefunc restart_file_f;char *restart_file_;



void dnsdata_1read_initial_data(){{struct freefunc* es=freestack;
 struct freefunc in_data_f;FILE *in_data_;

 char c;
in_data_=NULL;atblockexit(in_data_f,errfclose,&in_data_);errfopen(&in_data_,"dns.in",O_RDWR|O_CREAT);   if(!(scanrec( in_data_ ," ny = %d",&ny_)>0&&scanrec( in_data_ ," nx = %d",&nx_)>0&&scanrec( in_data_ ," nz = %d",&nz_)>0&&scanrec( in_data_ ," alfa0 = %lg",&alfa0_)>0&&scanrec( in_data_ ," beta0 = %lg",&beta0_)>0&&scanrec( in_data_ ," ymin = %lg",&ymin_)>0&&scanrec( in_data_ ," ymax = %lg",&ymax_)>0&&scanrec( in_data_ ," a = %lg",&a_)>0&&scanrec( in_data_ ," ni = %lg",&ni_)>0&&scanrec( in_data_ ," pr = %lg",&pr_)>0))ioerr( in_data_ );  ni_=1./ni_;  pr_=1./pr_;
 {do{  }while(   (scanrec( in_data_ ," meanpx = %lg",&meanpx_ )>0 ||scanrec( in_data_ ," meanflowx = %lg",&meanflowx_)>0));}  px_=meanpx_;
 {do{  }while(   (scanrec( in_data_ ," meanpz = %lg",&meanpz_ )>0 ||scanrec( in_data_ ," meanflowz = %lg",&meanflowz_)>0));}  pz_=meanpz_;
    if(!(scanrec( in_data_ ," u_conv = %lg",&u_conv_)>0 &&scanrec( in_data_ ," w_conv = %lg",&w_conv_)>0))ioerr( in_data_ );
    if(!(scanrec( in_data_ ," u0 = %lg",&u0_)>0 &&scanrec( in_data_ ," un = %lg",&un_)>0 &&scanrec( in_data_ ," w0 = %lg",&w0_)>0 &&scanrec( in_data_ ," wn = %lg",&wn_)>0 &&scanrec( in_data_ ," t0 = %lg",&t0_)>0 &&scanrec( in_data_ ," tn = %lg",&tn_)>0))ioerr( in_data_ );
 {do{  }while(   (scanrec( in_data_ ," deltat = %lg",&deltat_ )>0 ||scanrec( in_data_ ," cflmax = %lg",&cflmax_)>0));}
    if(!(scanrec( in_data_ ," t_max = %lg",&t_max_)>0 &&(scanrec( in_data_ ," time_from_restart = %c%*4[A-Za-z] ",&c)&&((time_from_restart_=(c=='T')||(c=='Y')||(c=='t')||(c=='y'))||(c=='F')||(c=='N')||(c=='f')||(c=='n'))) &&scanrec( in_data_ ," dt_field = %lg",&dt_field_)>0 &&scanrec( in_data_ ," dt_save = %lg",&dt_save_)>0))ioerr( in_data_ );
 if( !   (mygetline(" restart_file =",&restart_file_ , in_data_ ))){ if(restart_file_)free(restart_file_);restart_file_=strndup("",(int)(strlen("")-1)+1);};
 errfclose(&in_data_);
 if( (next_==NULL) ){
      fprintf(stdout,"""nproc=""");fprintf(stdout,"%d",nproc_);fprintf(stdout,"\t");fprintf(stdout,"""nsmp=""");fprintf(stdout,"%d",1);putc('\n',stdout);
      fprintf(stdout,"""nx=""");fprintf(stdout,"%d",nx_);fprintf(stdout,"\t" );fprintf(stdout,"""nz=""");fprintf(stdout,"%d",nz_);fprintf(stdout,"\t" );fprintf(stdout,"""ny=""");fprintf(stdout,"%d",ny_);fprintf(stdout,"\t" );fprintf(stdout,"""time=""");fprintf(stdout,"%g",time_);putc('\n',stdout);
      fprintf(stdout,"""meanflowx=""");fprintf(stdout,"%g",meanflowx_);fprintf(stdout,"\t" );fprintf(stdout,"""meanpx=""");fprintf(stdout,"%g",meanpx_);fprintf(stdout,"\t" );fprintf(stdout,"""meanflowz=""");fprintf(stdout,"%g",meanflowz_);fprintf(stdout,"\t" );fprintf(stdout,"""meanpz=""");fprintf(stdout,"%g",meanpz_);putc('\n',stdout);
      fprintf(stdout,"""ymin=""");fprintf(stdout,"%g",ymin_);fprintf(stdout,"\t" );fprintf(stdout,"""ymax=""");fprintf(stdout,"%g",ymax_);fprintf(stdout,"\t" );fprintf(stdout,"""a=""");fprintf(stdout,"%g",a_);fprintf(stdout,"\t" );fprintf(stdout,"""alfa0=""");fprintf(stdout,"%g",alfa0_);fprintf(stdout,"\t" );fprintf(stdout,"""beta0=""");fprintf(stdout,"%g",beta0_);fprintf(stdout,"\t" );fprintf(stdout,"""1/ni=""");fprintf(stdout,"%g",1./ni_);fprintf(stdout,"\t" );fprintf(stdout,"""1/pr=""");fprintf(stdout,"%g",1./pr_);putc('\n',stdout);
      fprintf(stdout,"""u_conv=""");fprintf(stdout,"%g",u_conv_);fprintf(stdout,"\t" );fprintf(stdout,"""u0=""");fprintf(stdout,"%g",u0_);fprintf(stdout,"\t" );fprintf(stdout,"""un=""");fprintf(stdout,"%g",un_);fprintf(stdout,"\t" );fprintf(stdout,"""w_conv=""");fprintf(stdout,"%g",w_conv_);fprintf(stdout,"\t" );fprintf(stdout,"""w0=""");fprintf(stdout,"%g",w0_);fprintf(stdout,"\t" );fprintf(stdout,"""wn=""");fprintf(stdout,"%g",wn_);fprintf(stdout,"\t" );fprintf(stdout,"""t0=""");fprintf(stdout,"%g",t0_);fprintf(stdout,"\t" );fprintf(stdout,"""tn=""");fprintf(stdout,"%g",tn_);putc('\n',stdout);
      fprintf(stdout,"""deltat=""");fprintf(stdout,"%g",deltat_);fprintf(stdout,"\t" );fprintf(stdout,"""cflmax=""");fprintf(stdout,"%g",cflmax_);fprintf(stdout,"\t" );fprintf(stdout,"""t_max=""");fprintf(stdout,"%g",t_max_);fprintf(stdout,"\t" );fprintf(stdout,"""dt_save=""");fprintf(stdout,"%g",dt_save_);fprintf(stdout,"\t" );fprintf(stdout,"""dt_field=""");fprintf(stdout,"%g",dt_field_);putc('\n',stdout);  
 };
freemem(es);}}

int reread_;

void dnsdata_2kill_received(int signum_){{struct freefunc* es=freestack;
 reread_=1;
}}

int dnsdata_4nyl;
/*nyl=dnsdata_4nyl*/
  int dnsdata_5nyh;
/*nyh=dnsdata_5nyh*/

int dnsdata_6M;
int dnsdata_7l;
int dnsdata_8m;
int dnsdata_9h;
ssize_t dnsdata_10i;
ssize_t dnsdata_11st;
struct freefunc y_f;char *y_;

/*!DO y(i)=ymin+(ymax-ymin)*i/ny FOR ALL i !Mesh equispaziata*/
/*!DO y(i)=ymin+(ymax-ymin)*[tanh(a*(i/ny-1))/tanh(a)+1] FOR ALL i !Boundary layer*/
ssize_t dnsdata_13st;
struct dnsdata_s12{char d0_[(ssize_t)sizeof(double)*(2-(-2)+1)];char d1_[(ssize_t)sizeof(double)*(2-(-2)+1)];char d2_[(ssize_t)sizeof(double)*(2-(-2)+1)];char d4_[(ssize_t)sizeof(double)*(2-(-2)+1)];};int dnsdata_14M;
int dnsdata_15l;
int dnsdata_16m;
int dnsdata_17h;
ssize_t dnsdata_18i;
ssize_t dnsdata_19st;
struct freefunc derivatives_f;char *derivatives_;

char d040_[(ssize_t)sizeof(double)*(2-(-2)+1)];
char d140_[(ssize_t)sizeof(double)*(2-(-2)+1)];
char d240_[(ssize_t)sizeof(double)*(2-(-2)+1)];
char d340_[(ssize_t)sizeof(double)*(2-(-2)+1)];
char d14m1_[(ssize_t)sizeof(double)*(2-(-2)+1)];
char d24m1_[(ssize_t)sizeof(double)*(2-(-2)+1)];
char d04n_[(ssize_t)sizeof(double)*(2-(-2)+1)];
char d14n_[(ssize_t)sizeof(double)*(2-(-2)+1)];
char d24n_[(ssize_t)sizeof(double)*(2-(-2)+1)];
char d14np1_[(ssize_t)sizeof(double)*(2-(-2)+1)];
char d24np1_[(ssize_t)sizeof(double)*(2-(-2)+1)];


char dnsdata_setup_derivatives_M[(ssize_t)sizeof(double)*(4+1)*(4+1)];
char dnsdata_setup_derivatives_t[(ssize_t)sizeof(double)*(4+1)];

int dnsdata_setup_derivatives_20M;
int dnsdata_setup_derivatives_21m;
int dnsdata_setup_derivatives_22;
int dnsdata_setup_derivatives_23;
int dnsdata_25l;
int dnsdata_26h;
ssize_t dnsdata_27i;
ssize_t dnsdata_28i;
ssize_t dnsdata_29st;
ssize_t dnsdata_30st;
struct freefunc D2vmat_f;char *D2vmat_;
struct freefunc etamat_f;char *etamat_;

struct freefunc D0mat_f;char *D0mat_;

  char v0bc_[(ssize_t)sizeof(double)*(2-(-2)+1)*(-(-1)+1)];
ssize_t dnsdata_33st;
char vnbc_[(ssize_t)sizeof(double)*(2-(-2)+1)*(1+1)];
char eta0bc_[(ssize_t)sizeof(double)*(2-(-2)+1)*(-(-1)+1)];
char etanbc_[(ssize_t)sizeof(double)*(2-(-2)+1)*(1+1)];


void dnsdata_34applybc_0(const int eq_l,const int eq_h,const ssize_t eq_i,const int eq__l,const int eq__h,const ssize_t eq__i,char *eq___,char *bc_) {{struct freefunc* es=freestack;
   {int i_= - 1  ;do{{ (*(double *)(i_*eq__i+eq_i+eq___))-=(*(double *)((-2)*eq__i+eq_i+eq___))*(*(double *)(i_*(ssize_t)sizeof(double)-(ssize_t)sizeof(double)*(2-(-2)+1)+bc_))/(*(double *)((-2)*(ssize_t)sizeof(double)-(ssize_t)sizeof(double)*(2-(-2)+1)+bc_)) ;}i_+=1;}while(i_<=2);}
   {int i_=0  ;do{{ (*(double *)(i_*eq__i+eq_i+eq___))-=(*(double *)(-eq__i+eq_i+eq___))*(*(double *)(i_*(ssize_t)sizeof(double)+bc_))/(*(double *)(-(ssize_t)sizeof(double)+bc_)) ;}i_+=1;}while(i_<=2);}
   {int i_=0  ;do{{ (*(double *)((i_-1)*eq__i+2*eq_i+eq___))-=(*(double *)((-2)*eq__i+2*eq_i+eq___))*(*(double *)(i_*(ssize_t)sizeof(double)+bc_))/(*(double *)(-(ssize_t)sizeof(double)+bc_)) ;}i_+=1;}while(i_<=2);}
}}
void dnsdata_35applybc_n(const int eq_l,const int eq_h,const ssize_t eq_i,const int eq__l,const int eq__h,const ssize_t eq__i,char *eq___,char *bc_) {{struct freefunc* es=freestack;
   {int i_= - 2  ;do{{ (*(double *)(i_*eq__i+(ny_-1)*eq_i+eq___))-=(*(double *)(2*eq__i+(ny_-1)*eq_i+eq___))*(*(double *)(i_*(ssize_t)sizeof(double)+(ssize_t)sizeof(double)*(2-(-2)+1)+bc_))/(*(double *)(2*(ssize_t)sizeof(double)+(ssize_t)sizeof(double)*(2-(-2)+1)+bc_)) ;}i_+=1;}while(i_<=1);}
   {int i_= - 2  ;do{{ (*(double *)(i_*eq__i+(ny_-1)*eq_i+eq___))-=(*(double *)(eq__i+(ny_-1)*eq_i+eq___))*(*(double *)(i_*(ssize_t)sizeof(double)+bc_))/(*(double *)((ssize_t)sizeof(double)+bc_)) ;}i_+=1;}while(i_<=0);}
   {int i_= - 2  ;do{{ (*(double *)((i_+1)*eq__i+(ny_-2)*eq_i+eq___))-=(*(double *)(2*eq__i+(ny_-2)*eq_i+eq___))*(*(double *)(i_*(ssize_t)sizeof(double)+bc_))/(*(double *)((ssize_t)sizeof(double)+bc_)) ;}i_+=1;}while(i_<=0);}
}}

/*! Integral in y direction*/
void dnsdata_36yintegr(double *RESULT_,const int f_l,const int f_h,const ssize_t f_i,char *f__){{struct freefunc* es=freestack;
   {int iy_=((dnsdata_4nyl / 2))*2+1  ;while(iy_<=dnsdata_5nyh ){
   double _37yp1;
/*yp1=_37yp1*/
  double _38ym1;
/*ym1=_38ym1*/

   double _39a1;
/*a1=_39a1*/

   double _40a3;
/*a3=_40a3*/

   double _41a2;
/*a2=_41a2*/

   _37yp1=(*(double *)((iy_+1)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_));
_38ym1=(*(double *)((iy_-1)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_) );
_39a1=-1./3.*_38ym1+1./6.*_37yp1+1./6.*_37yp1*_37yp1/_38ym1;
_40a3=1./3.*_37yp1-1./6.*_38ym1-1./6.*_38ym1*_38ym1/_37yp1;
_41a2=_37yp1-_38ym1-_39a1-_40a3;
(*RESULT_)+=_39a1*(*(double *)((iy_-1)*f_i+f__)) + _41a2*(*(double *)(iy_*f_i+f__)) + _40a3*(*(double *)((iy_+1)*f_i+f__))    ;
  iy_+= 2 ;};}
}}

struct VELOCITY_{struct COMPLEX_ u_;struct COMPLEX_ v_;struct COMPLEX_ w_;};
struct MOMFLUX_{struct COMPLEX_ uu_;struct COMPLEX_ uv_;struct COMPLEX_ vv_;struct COMPLEX_ vw_;struct COMPLEX_ ww_;struct COMPLEX_ uw_;};
/*!INLINE FUNCTION OS(INTEGER iy,i)=0.5*[d4(i)-2*k2*d2(i)+k2*k2*d0(i)] !Vittori*/
/*!INLINE FUNCTION SQ(INTEGER iy,i)=0.5*[d2(i)-k2*d0(i)]               !Vittori*/



int nxd_;
  int nzd_;
  int dnsdata_37h;
int dnsdata_38h;
ssize_t dnsdata_39i;
ssize_t dnsdata_40i;
void Vd_free(void * ptr){munmap((char*)ptr,dnsdata_40i);}struct freefunc Vd_f;char *Vd_;

int dnsdata_41h;
int dnsdata_42h;
ssize_t dnsdata_43i;
ssize_t dnsdata_44i;
void VVd_free(void * ptr){munmap((char*)ptr,dnsdata_44i);}struct freefunc VVd_f;char *VVd_;

/*maxtimelevels=1*/

struct rhstype_{struct COMPLEX_ eta_;struct COMPLEX_ D2v_;};
struct VETA_{struct COMPLEX_ v_;struct COMPLEX_ eta_;};
int dnsdata_45h;
int dnsdata_46l;
int dnsdata_47h;
ssize_t dnsdata_48i;
ssize_t dnsdata_49i;
ssize_t dnsdata_50i;
ssize_t dnsdata_51st;
ssize_t dnsdata_52st;
void V_free(void * ptr){munmap((char*)ptr+dnsdata_52st,dnsdata_50i);}struct freefunc V_f;char *V_;

int dnsdata_53h;
int dnsdata_54l;
int dnsdata_55h;
int dnsdata_56M;
int dnsdata_57l;
int dnsdata_58m;
int dnsdata_59h;
ssize_t dnsdata_60i;
ssize_t dnsdata_61i;
ssize_t dnsdata_62i;
ssize_t dnsdata_63st;
ssize_t dnsdata_64st;
void oldrhs_free(void * ptr){munmap((char*)ptr+dnsdata_64st,dnsdata_62i);}struct freefunc oldrhs_f;char *oldrhs_;

int dnsdata_65h;
int dnsdata_66l;
int dnsdata_67h;
ssize_t dnsdata_68i;
ssize_t dnsdata_69i;
ssize_t dnsdata_70i;
ssize_t dnsdata_71st;
struct freefunc memrhs_f;char *memrhs_;



double u1zero_;
double w1zero_;


int ismp_;


int dnsdata_72h;
int dnsdata_73h;
int dnsdata_74l;
int dnsdata_75h;
off_t dnsdata_76i;
off_t dnsdata_77i;
off_t dnsdata_79i;
off_t dnsdata_80i;
off_t dnsdata_81i;
off_t dnsdata_82st;
off_t dnsdata_83st;
struct dnsdata_s78{char header_[(1023+1)];};struct freefunc diskimage_f;FILE *diskimage_;

int dnsdata_84h;
int dnsdata_85h;
int dnsdata_86h;
int dnsdata_87l;
int dnsdata_88h;
off_t dnsdata_89i;
off_t dnsdata_90i;
off_t dnsdata_92i;
off_t dnsdata_93st;
off_t dnsdata_94i;
off_t dnsdata_95i;
off_t dnsdata_96i;
off_t dnsdata_97st;
off_t dnsdata_98st;
struct dnsdata_s91{int nyimage_;int nximage_;int nzimage_;double timage_;double yminimage_;double ymaximage_;double aimage_;double alfa0image_;double beta0image_;double niimage_;};struct freefunc diskfield_f;FILE *diskfield_;

int cont_;
int outcont_;

struct freefunc time_file_f;FILE *time_file_;
  int miny_;
int maxy_;

double cfl_;
double cflm_;

void dnsdata_99getcfl(){{struct freefunc* es=freestack;
/*!nx OPPURE nxd?? Check tesi Ferro*/
double _100dx;
/*dx=_100dx*/
  double _101dz;
/*dz=_101dz*/

_100dx=3.14159265358979323846/(alfa0_*(double)(nxd_));
_101dz=2.*3.14159265358979323846/(beta0_*(double)(nzd_));
cfl_=0.;
 {int iy_=dnsdata_4nyl  ;while(iy_<=dnsdata_5nyh){
  double dy_;

  double _131;
double _132;
double _133;
double _134M;
dy_=0.5*((*(double *)((iy_+1)*(ssize_t)sizeof(double)+y_))-(*(double *)((iy_-1)*(ssize_t)sizeof(double)+y_)));fflush(NULL); ismp_=0  ;while(ismp_<1-1&&fork()){ismp_+=1;;};{

     {int ix_=ismp_  ;while(ix_<=nx_ ){
      int _102h;
int _103h;

      int _106l;
int _107h;
ssize_t _108st;
ssize_t _109i;
int _110l;
int _111l;

      _102h=nz_;
_103h=nz_;
{char *_105_;

_105_=iy_*(ssize_t)sizeof(struct VELOCITY_)+ix_*dnsdata_49i+V_; {char *_104_=ix_*dnsdata_39i+Vd_;int _104_1=_102h; do{{ (*(struct VELOCITY_ *)(_104_))=(*(struct VELOCITY_ *)(_105_)); _105_ =dnsdata_48i+_105_;}_104_+=(ssize_t)sizeof(struct VELOCITY_);_104_1--;}while(_104_1>=0);}}_106l=nz_+1;
_107h=nzd_-nz_-1;
_108st=_106l*(ssize_t)sizeof(struct VELOCITY_);
_109i=(ssize_t)sizeof(struct VELOCITY_)*(_107h-_106l+1);
memset(_108st+ix_*dnsdata_39i+Vd_,0,_109i);
      _110l= - nz_;
_111l= - nz_;
{char *_113_;

_113_=_110l*dnsdata_48i+iy_*(ssize_t)sizeof(struct VELOCITY_)+ix_*dnsdata_49i+V_; {char *_112_=_110l*(ssize_t)sizeof(struct VELOCITY_)+nzd_*(ssize_t)sizeof(struct VELOCITY_)+ix_*dnsdata_39i+Vd_;int _112_1=(-1)-_110l; do{{ (*(struct VELOCITY_ *)(_112_))=(*(struct VELOCITY_ *)(_113_)); _113_ =dnsdata_48i+_113_;}_112_+=(ssize_t)sizeof(struct VELOCITY_);_112_1--;}while(_112_1>=0);}}{ char *_114w;
_114w=ix_*dnsdata_39i+Vd_;
{fft_1IFT(0,dnsdata_38h,(ssize_t)sizeof(struct VELOCITY_),((char*)&(*(struct VELOCITY_ *)(_114w)).u_),0,dnsdata_38h,(ssize_t)sizeof(struct VELOCITY_),((char*)&(*(struct VELOCITY_ *)(_114w)).u_));}; {fft_1IFT(0,dnsdata_38h,(ssize_t)sizeof(struct VELOCITY_),((char*)&(*(struct VELOCITY_ *)(_114w)).v_),0,dnsdata_38h,(ssize_t)sizeof(struct VELOCITY_),((char*)&(*(struct VELOCITY_ *)(_114w)).v_));}; {fft_1IFT(0,dnsdata_38h,(ssize_t)sizeof(struct VELOCITY_),((char*)&(*(struct VELOCITY_ *)(_114w)).w_),0,dnsdata_38h,(ssize_t)sizeof(struct VELOCITY_),((char*)&(*(struct VELOCITY_ *)(_114w)).w_));};}
    ix_+= 1;};}
    if( ismp_==0 ){ int _115l;
int _116h;
ssize_t _117st;
ssize_t _118i;
_115l=nx_+1;
_116h=nxd_-1;
_117st=_115l*dnsdata_39i;
_118i=dnsdata_39i*(_116h-_115l+1);
memset(_117st+Vd_,0,_118i);};
    {
  register int md119;
while(!((*barrier_)==(ismp_)))sigsuspend(&oldmask);
  (*barrier_)=(md119=((ismp_)+1) % (1),md119>=0?md119:md119+(1));  kill(0,SIGUSR1);
  while(!((*barrier_)<=(ismp_)))sigsuspend(&oldmask);
};
     {int iz_=ismp_  ;do{{ { char *_120w;
_120w=iz_*(ssize_t)sizeof(struct VELOCITY_)+Vd_;
{fft_3RFT(0,dnsdata_37h,dnsdata_39i,((char*)&(*(struct VELOCITY_ *)(_120w)).u_),0,dnsdata_37h,dnsdata_39i,((char*)&(*(struct VELOCITY_ *)(_120w)).u_));}; {fft_3RFT(0,dnsdata_37h,dnsdata_39i,((char*)&(*(struct VELOCITY_ *)(_120w)).v_),0,dnsdata_37h,dnsdata_39i,((char*)&(*(struct VELOCITY_ *)(_120w)).v_));}; {fft_3RFT(0,dnsdata_37h,dnsdata_39i,((char*)&(*(struct VELOCITY_ *)(_120w)).w_),0,dnsdata_37h,dnsdata_39i,((char*)&(*(struct VELOCITY_ *)(_120w)).w_));} ;}}iz_+= 1;}while(iz_<=dnsdata_38h );}
    {
  register int md121;
while(!((*barrier_)==(ismp_)))sigsuspend(&oldmask);
  (*barrier_)=(md121=((ismp_)+1) % (1),md121>=0?md121:md121+(1));  kill(0,SIGUSR1);
  while(!((*barrier_)<=(ismp_)))sigsuspend(&oldmask);
};
  } if(ismp_<1-1)exit(0);;
 ismp_=0  ;while(ismp_<1-1){if(wait(NULL)<0)traphandler("wait");ismp_+=1;;};
  /*! Un campione ogni due*/
   _131=-DBL_MAX;  {int _122i_=dnsdata_37h;do{{int _123i_=dnsdata_38h;do{{double _124M;
_124M=fabs((*(double *)(_123i_*(ssize_t)sizeof(struct VELOCITY_)+_122i_*dnsdata_39i+(char*)&(*(struct COMPLEX_*)(&(*(struct VELOCITY_*)(Vd_)).u_)).IMAG_))) ;
if(_131<_124M)_131=_124M;}_123i_--;}while(_123i_>=0);}_122i_--;}while(_122i_>=0);} _132=-DBL_MAX;  {int _125i_=dnsdata_37h;do{{int _126i_=dnsdata_38h;do{{double _127M;
_127M=fabs((*(double *)(_126i_*(ssize_t)sizeof(struct VELOCITY_)+_125i_*dnsdata_39i+(char*)&(*(struct COMPLEX_*)(&(*(struct VELOCITY_*)(Vd_)).v_)).IMAG_))) ;
if(_132<_127M)_132=_127M;}_126i_--;}while(_126i_>=0);}_125i_--;}while(_125i_>=0);} _133=-DBL_MAX;  {int _128i_=dnsdata_37h;do{{int _129i_=dnsdata_38h;do{{double _130M;
_130M=fabs((*(double *)(_129i_*(ssize_t)sizeof(struct VELOCITY_)+_128i_*dnsdata_39i+(char*)&(*(struct COMPLEX_*)(&(*(struct VELOCITY_*)(Vd_)).w_)).IMAG_))) ;
if(_133<_130M)_133=_130M;}_129i_--;}while(_129i_>=0);}_128i_--;}while(_128i_>=0);}_134M=_131/_100dx+_132/dy_+_133/_101dz;
cfl_=cfl_;if(cfl_<_134M)cfl_=_134M;
iy_+=1;};}
}}

double energy_;
double slice_energy_;
double diss_;
double slice_diss_; 

struct COMPLEX_ dudy_;
struct COMPLEX_ dvdy_;
struct COMPLEX_ dwdy_;

int dnsdata_100h;
int dnsdata_101l;
int dnsdata_102h;
ssize_t dnsdata_103i;
ssize_t dnsdata_104i;
ssize_t dnsdata_105st;
struct freefunc fieldbuf_f;char *fieldbuf_;

int dnsdata_106h;
int dnsdata_107l;
int dnsdata_108h;
ssize_t dnsdata_109i;
ssize_t dnsdata_110i;
ssize_t dnsdata_111st;
struct freefunc velbuf_f;char *velbuf_;

void dnsdata_112outstats(){{struct freefunc* es=freestack;
outcont_+=1;  
if( outcont_>0 ){
	outcont_=0;  dnsdata_99getcfl();  cflm_=0.;  energy_=0.;  slice_energy_=0.;  diss_=0.;  slice_diss_=0.;

	 {int iy_=dnsdata_4nyl  ;do{  {int ix_=dnsdata_45h;do{{int iz_=dnsdata_46l;do{ if(!( (ix_==0 )&&( iz_==0))){ { 
	struct VELOCITY_ *_113w;
_113w=(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_);
 slice_energy_ +=  1./2.* (((*_113w).u_.REAL_*(*_113w).u_.REAL_+(*_113w).u_.IMAG_*(*_113w).u_.IMAG_)+((*_113w).v_.REAL_*(*_113w).v_.REAL_+(*_113w).v_.IMAG_*(*_113w).v_.IMAG_)+((*_113w).w_.REAL_*(*_113w).w_.REAL_+(*_113w).w_.IMAG_*(*_113w).w_.IMAG_))*(double)((ix_==0?1:2))*((*(double *)((iy_+1)*(ssize_t)sizeof(double)+y_))-(*(double *)((iy_-1)*(ssize_t)sizeof(double)+y_)))*0.5 ;}}iz_++;}while(iz_<=dnsdata_47h);}ix_--;}while(ix_>=0);}iy_+=1;}while(iy_<=dnsdata_5nyh );}

	 {int iy_=dnsdata_4nyl  ;while(iy_<=dnsdata_5nyh){
		 {int ix_=1  ;while(ix_<=nx_ ){  {int iz_=dnsdata_46l;do{ {
			char *_114w;
double _115k2;
/*k2=_115k2*/

			double _116r;
double _117i;
double _118r;
double _119r;
double _120i;
double _121r;
double _122r;
double _123i;
double _124r;
double _125i;
double _126r;
double _127r;
double _128i;
double _129r;
double _130r;
double _131i;
double _132r;
double _133i;
double _134r;
double _135r;
double _136i;
double _137r;
double _138r;
double _139i;
_114w=iz_*dnsdata_48i+ix_*dnsdata_49i+V_;
_115k2=pow((alfa0_*(double)(ix_)),2 )+ pow((beta0_*(double)(iz_)),2);
_116r=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).REAL_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).REAL_));
_117i=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).IMAG_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).IMAG_));
_118r=(1./(((*(double *)((iy_+1)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))) ));
_119r=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).REAL_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).REAL_));
_120i=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).IMAG_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).IMAG_));
_121r=(1./(((*(double *)(iy_*(ssize_t)sizeof(double)+y_))-(*(double *)((iy_-1)*(ssize_t)sizeof(double)+y_)))));
_122r=((_116r*_118r)+(_119r*_121r));
_123i=((_117i*_118r)+(_120i*_121r));
 {register double temp=(0.5*_122r);dudy_ .IMAG_=(0.5*_123i);dudy_ .REAL_=temp;};
			_124r=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).REAL_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).REAL_));
_125i=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).IMAG_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).IMAG_));
_126r=(1./(((*(double *)((iy_+1)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))) ));
_127r=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).REAL_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).REAL_));
_128i=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).IMAG_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).IMAG_));
_129r=(1./(((*(double *)(iy_*(ssize_t)sizeof(double)+y_))-(*(double *)((iy_-1)*(ssize_t)sizeof(double)+y_)))));
_130r=((_124r*_126r)+(_127r*_129r));
_131i=((_125i*_126r)+(_128i*_129r));
 {register double temp=(0.5*_130r);dvdy_ .IMAG_=(0.5*_131i);dvdy_ .REAL_=temp;};
			_132r=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).REAL_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).REAL_));
_133i=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).IMAG_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).IMAG_));
_134r=(1./(((*(double *)((iy_+1)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))) ));
_135r=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).REAL_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).REAL_));
_136i=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).IMAG_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).IMAG_));
_137r=(1./(((*(double *)(iy_*(ssize_t)sizeof(double)+y_))-(*(double *)((iy_-1)*(ssize_t)sizeof(double)+y_)))));
_138r=((_132r*_134r)+(_135r*_137r));
_139i=((_133i*_134r)+(_136i*_137r));
 {register double temp=(0.5*_138r);dwdy_ .IMAG_=(0.5*_139i);dwdy_ .REAL_=temp;};
			 slice_diss_ +=  2.* 0.5*( _115k2*(((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).REAL_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).REAL_+(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).IMAG_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).u_)).IMAG_)+((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).REAL_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).REAL_+(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).IMAG_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).v_)).IMAG_)+((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).REAL_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).REAL_+(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).IMAG_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_114w)).w_)).IMAG_)) + (dudy_.REAL_*dudy_.REAL_+dudy_.IMAG_*dudy_.IMAG_)+(dvdy_.REAL_*dvdy_.REAL_+dvdy_.IMAG_*dvdy_.IMAG_)+(dwdy_.REAL_*dwdy_.REAL_+dwdy_.IMAG_*dwdy_.IMAG_) ) * ((*(double *)((iy_+1)*(ssize_t)sizeof(double)+y_))-(*(double *)((iy_-1)*(ssize_t)sizeof(double)+y_)))*0.5;
		}iz_++;}while(iz_<=dnsdata_47h);}ix_+=1;};}
		  {int iz_=dnsdata_46l;do{ if(!(iz_==0 )){{
			char *_140w;
double _141k2;
/*k2=_141k2*/

			double _142r;
double _143i;
double _144r;
double _145r;
double _146i;
double _147r;
double _148r;
double _149i;
double _150r;
double _151i;
double _152r;
double _153r;
double _154i;
double _155r;
double _156r;
double _157i;
double _158r;
double _159i;
double _160r;
double _161r;
double _162i;
double _163r;
double _164r;
double _165i;
_140w=iz_*dnsdata_48i+V_;
_141k2=pow((beta0_*(double)(iz_)),2);
_142r=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).REAL_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).REAL_));
_143i=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).IMAG_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).IMAG_));
_144r=(1./(((*(double *)((iy_+1)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))) ));
_145r=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).REAL_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).REAL_));
_146i=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).IMAG_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).IMAG_));
_147r=(1./(((*(double *)(iy_*(ssize_t)sizeof(double)+y_))-(*(double *)((iy_-1)*(ssize_t)sizeof(double)+y_)))));
_148r=((_142r*_144r)+(_145r*_147r));
_149i=((_143i*_144r)+(_146i*_147r));
 {register double temp=(0.5*_148r);dudy_ .IMAG_=(0.5*_149i);dudy_ .REAL_=temp;};
			_150r=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).REAL_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).REAL_));
_151i=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).IMAG_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).IMAG_));
_152r=(1./(((*(double *)((iy_+1)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))) ));
_153r=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).REAL_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).REAL_));
_154i=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).IMAG_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).IMAG_));
_155r=(1./(((*(double *)(iy_*(ssize_t)sizeof(double)+y_))-(*(double *)((iy_-1)*(ssize_t)sizeof(double)+y_)))));
_156r=((_150r*_152r)+(_153r*_155r));
_157i=((_151i*_152r)+(_154i*_155r));
 {register double temp=(0.5*_156r);dvdy_ .IMAG_=(0.5*_157i);dvdy_ .REAL_=temp;};
			_158r=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).REAL_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).REAL_));
_159i=((*(struct COMPLEX_*)((iy_+1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).IMAG_-((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).IMAG_));
_160r=(1./(((*(double *)((iy_+1)*(ssize_t)sizeof(double)+y_))-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))) ));
_161r=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).REAL_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).REAL_));
_162i=((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).IMAG_-((*(struct COMPLEX_*)((iy_-1)*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).IMAG_));
_163r=(1./(((*(double *)(iy_*(ssize_t)sizeof(double)+y_))-(*(double *)((iy_-1)*(ssize_t)sizeof(double)+y_)))));
_164r=((_158r*_160r)+(_161r*_163r));
_165i=((_159i*_160r)+(_162i*_163r));
 {register double temp=(0.5*_164r);dwdy_ .IMAG_=(0.5*_165i);dwdy_ .REAL_=temp;};
			 slice_diss_ +=  0.5*( _141k2*(((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).REAL_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).REAL_+(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).IMAG_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).u_)).IMAG_)+((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).REAL_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).REAL_+(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).IMAG_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).v_)).IMAG_)+((*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).REAL_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).REAL_+(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).IMAG_*(*(struct COMPLEX_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct VELOCITY_*)(_140w)).w_)).IMAG_)) + (dudy_.REAL_*dudy_.REAL_+dudy_.IMAG_*dudy_.IMAG_)+(dvdy_.REAL_*dvdy_.REAL_+dvdy_.IMAG_*dvdy_.IMAG_)+(dwdy_.REAL_*dwdy_.REAL_+dwdy_.IMAG_*dwdy_.IMAG_) ) * ((*(double *)((iy_+1)*(ssize_t)sizeof(double)+y_))-(*(double *)((iy_-1)*(ssize_t)sizeof(double)+y_)))*0.5;
		}}iz_++;}while(iz_<=dnsdata_47h);}
	iy_+=1;};}
	if( !(prev_==NULL) ){ 
		  if(!(fread(0+&energy_,(ssize_t)sizeof(double),1, prev_ )==1&& fread(0+&cflm_,(ssize_t)sizeof(double),1, prev_ )==1&& fread(0+&diss_,(ssize_t)sizeof(double),1, prev_ )==1))ioerr( prev_ );  fflush(prev_);
		energy_+=slice_energy_;  diss_+=slice_diss_;  /*!cflm=MAX(cfl,cflm) */
		if( cfl_ >cflm_ ){  cflm_ = cfl_; };
  	}else{ 
		energy_=slice_energy_;  diss_=slice_diss_;  cflm_=cfl_;
	};
	if( !(next_==NULL) ){ fwrite(&energy_,(ssize_t)sizeof(double),1,next_); fwrite(&cflm_,(ssize_t)sizeof(double),1,next_); fwrite(&diss_,(ssize_t)sizeof(double),1,next_); fflush(next_);};
	if( cflmax_>0.){ 
		deltat_=cflmax_/cflm_;
		if( !(next_==NULL) ){   if(!(fread(0+&deltat_,(ssize_t)sizeof(double),1, next_ )==1))ioerr( next_ ); fflush(next_);};
		if( !(prev_==NULL) ){ fwrite(&deltat_,(ssize_t)sizeof(double),1,prev_); fflush(prev_);};
	};

	if( (next_==NULL) ){
	  double _166;
double _167;
double _168;
double _169;
 _166=0.; {int i_= - 2  ;do{{(*&_166)+= - (*(double *)(i_*(ssize_t)sizeof(double)+d14n_-((-2)*(ssize_t)sizeof(double))))*(*(struct VELOCITY_ *)((ny_-1+i_)*(ssize_t)sizeof(struct VELOCITY_)+V_)).u_.REAL_ ;}i_+=1;}while(i_<=2 );} _167=0.; {int i_= - 2  ;do{{(*&_167)+= - (*(double *)(i_*(ssize_t)sizeof(double)+d14n_-((-2)*(ssize_t)sizeof(double))))*(*(struct VELOCITY_ *)((ny_-1+i_)*(ssize_t)sizeof(struct VELOCITY_)+V_)).w_.REAL_ ;}i_+=1;}while(i_<=2 );} fprintf(stdout,"%1.9g\t%1.9g\t%1.9g\t%1.9g\t%1.9g\t%g\t%g\t%g\t%g\t%g\t%g\t%g\t%g",time_ ,u1zero_ ,_166
        	,w1zero_  ,_167
		,flowx_,px_+corrpx_,flowz_,pz_+corrpz_,cflm_*deltat_,deltat_,energy_,diss_);putc('\n',stdout);
	   _168=0.; {int i_= - 2  ;do{{(*&_168)+= - (*(double *)(i_*(ssize_t)sizeof(double)+d14n_-((-2)*(ssize_t)sizeof(double))))*(*(struct VELOCITY_ *)((ny_-1+i_)*(ssize_t)sizeof(struct VELOCITY_)+V_)).u_.REAL_ ;}i_+=1;}while(i_<=2 );} _169=0.; {int i_= - 2  ;do{{(*&_169)+= - (*(double *)(i_*(ssize_t)sizeof(double)+d14n_-((-2)*(ssize_t)sizeof(double))))*(*(struct VELOCITY_ *)((ny_-1+i_)*(ssize_t)sizeof(struct VELOCITY_)+V_)).w_.REAL_ ;}i_+=1;}while(i_<=2 );} fprintf( time_file_ ,"%1.9g\t%1.9g\t%1.9g\t%1.9g\t%1.9g\t%g\t%g\t%g\t%g\t%g\t%g\t%g\t%g",time_ 
        	,u1zero_ ,_168
	        ,w1zero_  ,_169
	        ,flowx_,px_+corrpx_,flowz_,pz_+corrpz_,cflm_*deltat_,deltat_,energy_,diss_);putc('\n', time_file_ );  fflush(time_file_);
};
};
    	
if( (time_>0.)&&( (int)floor((time_+0.5*deltat_)/dt_save_) >(int)floor((time_-0.5*deltat_)/dt_save_) )){
    {int iy_=(dnsdata_4nyl-2);do{{ { struct VELOCITY_ *_170w;
_170w=(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+V_);
{register double temp=(*_170w).u_.REAL_-u_conv_;(*_170w).u_.IMAG_=(*_170w).u_.IMAG_;(*_170w).u_.REAL_=temp;}; {register double temp=(*_170w).w_.REAL_-w_conv_;(*_170w).w_.IMAG_=(*_170w).w_.IMAG_;(*_170w).w_.REAL_=temp;};}}iy_++;}while(iy_<=(dnsdata_5nyh+2));}
  if( !(prev_==NULL) ){  while(!feof( prev_)&&getc( prev_)!='\n'){};};
   errfopen(&diskimage_ ,"Dati.cart.out",O_RDWR|O_CREAT);
  {
    if( (next_==NULL) ){
      char *_171; fprintf(stdout,"""Writing Dati.cart.out at time""\t%g" ,time_);putc('\n',stdout);
      _171=malloc(snprintf(NULL,0,"         ny=""%d""       nx=""%d""       nz=""%d""\n"
"         alfa0=""%g""     beta0=""%g""\n"
"         ymin=""%g""       ymax=""%g""       a=""%g""\n"
"         ni=""%g""       time=""%g""\n"
"         """,ny_,nx_,nz_,alfa0_,beta0_,ymin_,ymax_,a_,1./ni_,time_)+1);sprintf(_171,"         ny=""%d""       nx=""%d""       nz=""%d""\n"
"         alfa0=""%g""     beta0=""%g""\n"
"         ymin=""%g""       ymax=""%g""       a=""%g""\n"
"         ni=""%g""       time=""%g""\n"
"         """,ny_,nx_,nz_,alfa0_,beta0_,ymin_,ymax_,a_,1./ni_,time_); fprintf( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_),"%s",_171);putc('\n', (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_));
    free(_171);};

    {int iy_=  miny_  ;while(iy_<=maxy_){
       {int iz_=dnsdata_107l;do{{ int _172h;
int _173h;
_172h=nx_;
_173h=nx_;
{char *_175_;

_175_=iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+V_; {char *_174_=iz_*(ssize_t)sizeof(struct VELOCITY_)+velbuf_;int _174_1=_172h; do{{ (*(struct VELOCITY_ *)(_174_))=(*(struct VELOCITY_ *)(_175_)); _175_ =dnsdata_49i+_175_;}_174_+=dnsdata_109i;_174_1--;}while(_174_1>=0);}} }iz_++;}while(iz_<=dnsdata_108h);}
        {int _176i_=dnsdata_73h;do{{if((ssize_t)sizeof(struct VELOCITY_)==(ssize_t)sizeof(struct VELOCITY_)&&(ssize_t)sizeof(struct VELOCITY_)==(ssize_t)sizeof(struct VELOCITY_)){if(!(fseeko(diskimage_,_176i_*(off_t)dnsdata_76i+iy_*(off_t)dnsdata_77i+(off_t)((ssize_t)sizeof(struct dnsdata_s78)-dnsdata_83st+(ssize_t)(char*)(struct dnsdata_s78*)(0))+dnsdata_82st,SEEK_SET)==0&&fwrite(_176i_*dnsdata_109i+velbuf_+dnsdata_82st,(ssize_t)sizeof(struct VELOCITY_),dnsdata_75h-dnsdata_74l+1,diskimage_)==dnsdata_75h-dnsdata_74l+1))ioerr(diskimage_);}else{  {int _177i_=dnsdata_74l;do{{if(!(fseeko(diskimage_,_177i_*(off_t)(ssize_t)sizeof(struct VELOCITY_)+_176i_*(off_t)dnsdata_76i+iy_*(off_t)dnsdata_77i+(off_t)((ssize_t)sizeof(struct dnsdata_s78)-dnsdata_83st+(ssize_t)(char*)(struct dnsdata_s78*)(0)),SEEK_SET)==0&&fwrite((struct VELOCITY_*)(_177i_*(ssize_t)sizeof(struct VELOCITY_)+_176i_*dnsdata_109i+velbuf_),(ssize_t)sizeof(struct VELOCITY_),1,diskimage_)==1))ioerr(diskimage_);}_177i_++;}while(_177i_<=dnsdata_75h);}};}_176i_--;}while(_176i_>=0);}
iy_+=1;};}
 {int i_=0  ;do{{ char _178;
if(!(fseeko(diskimage_,i_+(ssize_t)(*(struct dnsdata_s78*)(0)).header_ ,SEEK_SET)==0&&fread(&_178,1,1,diskimage_)==1))ioerr(diskimage_); fprintf(stdout,"%d\t%c",i_,_178);putc('\n',stdout);}i_+=1;}while(i_<=1023);}
  errfclose(&diskimage_);
  if( !(next_==NULL) ){  putc('\n', next_);};
    {int iy_=(dnsdata_4nyl-2);do{{ { struct VELOCITY_ *_179w;
_179w=(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+V_);
{register double temp=(*_179w).u_.REAL_+u_conv_;(*_179w).u_.IMAG_=(*_179w).u_.IMAG_;(*_179w).u_.REAL_=temp;}; {register double temp=(*_179w).w_.REAL_+w_conv_;(*_179w).w_.IMAG_=(*_179w).w_.IMAG_;(*_179w).w_.REAL_=temp;};}}iy_++;}while(iy_<=(dnsdata_5nyh+2));}
}};
    
if( (time_>0.)&&( (int)floor((time_+0.5*deltat_)/dt_field_) >(int)floor((time_-0.5*deltat_)/dt_field_) )){
  struct freefunc field_name_f;char *field_name_;

  cont_+=1;  field_name_=0;atblockexit(field_name_f,condfree,field_name_); {char *tmp; tmp=malloc(snprintf(NULL,0,"""Field""%d"".fld""",cont_)+1); sprintf(tmp,"""Field""%d"".fld""",cont_); if(field_name_ )free(field_name_ );field_name_ =tmp;}
    {int iy_=(dnsdata_4nyl-2);do{{ { struct VELOCITY_ *_180w;
_180w=(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+V_);
{register double temp=(*_180w).u_.REAL_-u_conv_;(*_180w).u_.IMAG_=(*_180w).u_.IMAG_;(*_180w).u_.REAL_=temp;}; {register double temp=(*_180w).w_.REAL_-w_conv_;(*_180w).w_.IMAG_=(*_180w).w_.IMAG_;(*_180w).w_.REAL_=temp;};}}iy_++;}while(iy_<=(dnsdata_5nyh+2));}
  if( !(prev_==NULL) ){  while(!feof( prev_)&&getc( prev_)!='\n'){};};
   errfopen(&diskfield_ ,field_name_,O_RDWR|O_CREAT);
  {
    int _182l;
int _183h;
int _184l;
int _185h;
ssize_t _186st;
int _188l;
int _189h;
int _190l;
int _191h;
ssize_t _192st;
if( (next_==NULL) ){
      double fwrite181_;

     fprintf(stdout,"""Writing field_file""\t%d\t""at time""\t%g" ,cont_  ,time_);putc('\n',stdout);
      if(!(fseeko(diskfield_,(ssize_t)&(*(struct dnsdata_s91*)(0)).nyimage_,SEEK_SET)==0&&fwrite(&ny_,(ssize_t)sizeof(int),1,diskfield_)==1))ioerr(diskfield_); if(!(fseeko(diskfield_,(ssize_t)&(*(struct dnsdata_s91*)(0)).nximage_,SEEK_SET)==0&&fwrite(&nx_,(ssize_t)sizeof(int),1,diskfield_)==1))ioerr(diskfield_); if(!(fseeko(diskfield_,(ssize_t)&(*(struct dnsdata_s91*)(0)).nzimage_,SEEK_SET)==0&&fwrite(&nz_,(ssize_t)sizeof(int),1,diskfield_)==1))ioerr(diskfield_);
      if(!(fseeko(diskfield_,(ssize_t)&(*(struct dnsdata_s91*)(0)).timage_,SEEK_SET)==0&&fwrite(&time_,(ssize_t)sizeof(double),1,diskfield_)==1))ioerr(diskfield_); if(!(fseeko(diskfield_,(ssize_t)&(*(struct dnsdata_s91*)(0)).yminimage_,SEEK_SET)==0&&fwrite(&ymin_,(ssize_t)sizeof(double),1,diskfield_)==1))ioerr(diskfield_); if(!(fseeko(diskfield_,(ssize_t)&(*(struct dnsdata_s91*)(0)).ymaximage_,SEEK_SET)==0&&fwrite(&ymax_,(ssize_t)sizeof(double),1,diskfield_)==1))ioerr(diskfield_);
      if(!(fseeko(diskfield_,(ssize_t)&(*(struct dnsdata_s91*)(0)).aimage_,SEEK_SET)==0&&fwrite(&a_,(ssize_t)sizeof(double),1,diskfield_)==1))ioerr(diskfield_); if(!(fseeko(diskfield_,(ssize_t)&(*(struct dnsdata_s91*)(0)).alfa0image_,SEEK_SET)==0&&fwrite(&alfa0_,(ssize_t)sizeof(double),1,diskfield_)==1))ioerr(diskfield_); if(!(fseeko(diskfield_,(ssize_t)&(*(struct dnsdata_s91*)(0)).beta0image_,SEEK_SET)==0&&fwrite(&beta0_,(ssize_t)sizeof(double),1,diskfield_)==1))ioerr(diskfield_); fwrite181_=1./ni_;if(!(fseeko(diskfield_,(ssize_t)&(*(struct dnsdata_s91*)(0)).niimage_,SEEK_SET)==0&&fwrite(&fwrite181_,(ssize_t)sizeof(double),1,diskfield_)==1))ioerr(diskfield_);};
    _182l=miny_;
_183h=maxy_;
_184l=miny_;
_185h=maxy_;
_186st=_182l*(ssize_t)sizeof(double);
if((ssize_t)sizeof(double)==(ssize_t)sizeof(double)&&(ssize_t)sizeof(struct VELOCITY_)==(ssize_t)sizeof(double)){if(!(fseeko(diskfield_,(off_t)((ssize_t)sizeof(struct dnsdata_s91)-dnsdata_93st+(ssize_t)(char*)(struct dnsdata_s91*)(0))+_186st,SEEK_SET)==0&&fwrite((char*)&(*(struct COMPLEX_*)(&(*(struct VELOCITY_*)(V_)).u_)).REAL_+_186st,(ssize_t)sizeof(double),_183h-_182l+1,diskfield_)==_183h-_182l+1))ioerr(diskfield_);}else{  {int _187i_=_182l;do{{if(!(fseeko(diskfield_,_187i_*(off_t)(ssize_t)sizeof(double)+(off_t)((ssize_t)sizeof(struct dnsdata_s91)-dnsdata_93st+(ssize_t)(char*)(struct dnsdata_s91*)(0)),SEEK_SET)==0&&fwrite((double*)(_187i_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct COMPLEX_*)(&(*(struct VELOCITY_*)(V_)).u_)).REAL_),(ssize_t)sizeof(double),1,diskfield_)==1))ioerr(diskfield_);}_187i_++;}while(_187i_<=_183h);}};
    _188l=miny_;
_189h=maxy_;
_190l=miny_;
_191h=maxy_;
_192st=_188l*(ssize_t)sizeof(double);
if((ssize_t)sizeof(double)==(ssize_t)sizeof(double)&&(ssize_t)sizeof(struct VELOCITY_)==(ssize_t)sizeof(double)){if(!(fseeko(diskfield_,(off_t)(((ssize_t)sizeof(struct dnsdata_s91)+dnsdata_92i)-dnsdata_93st+(ssize_t)(char*)(struct dnsdata_s91*)(0))+_192st,SEEK_SET)==0&&fwrite((char*)&(*(struct COMPLEX_*)(&(*(struct VELOCITY_*)(V_)).w_)).REAL_+_192st,(ssize_t)sizeof(double),_189h-_188l+1,diskfield_)==_189h-_188l+1))ioerr(diskfield_);}else{  {int _193i_=_188l;do{{if(!(fseeko(diskfield_,_193i_*(off_t)(ssize_t)sizeof(double)+(off_t)(((ssize_t)sizeof(struct dnsdata_s91)+dnsdata_92i)-dnsdata_93st+(ssize_t)(char*)(struct dnsdata_s91*)(0)),SEEK_SET)==0&&fwrite((double*)(_193i_*(ssize_t)sizeof(struct VELOCITY_)+(char*)&(*(struct COMPLEX_*)(&(*(struct VELOCITY_*)(V_)).w_)).REAL_),(ssize_t)sizeof(double),1,diskfield_)==1))ioerr(diskfield_);}_193i_++;}while(_193i_<=_189h);}};

     {int iy_=  miny_  ;while(iy_<=maxy_){
       {int ix_=dnsdata_100h;do{{int iz_=dnsdata_101l;do{ {
      struct VETA_ *_194w;
double _195r;
double _197r_196ialfa;
double _198i_196ialfa;
/*ialfa=_197r_196ialfa,_198i_196ialfa*/
  double _199r;
double _201r_200ibeta;
double _202i_200ibeta;
/*ibeta=_201r_200ibeta,_202i_200ibeta*/

      _194w=(struct VETA_ *)(iz_*(ssize_t)sizeof(struct VETA_)+ix_*dnsdata_103i+fieldbuf_);
 {register double temp=(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_)).v_.REAL_;(*_194w).v_ .IMAG_=(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_)).v_.IMAG_;(*_194w).v_ .REAL_=temp;};
      _195r=alfa0_*(double)(ix_);
_197r_196ialfa=0.;
_198i_196ialfa=_195r;
_199r=beta0_*(double)(iz_);
_201r_200ibeta=0.;
_202i_200ibeta=_199r;
 {register double temp=(_201r_200ibeta*(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_)).u_.REAL_-_202i_200ibeta*(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_)).u_.IMAG_)-(_197r_196ialfa*(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_)).w_.REAL_-_198i_196ialfa*(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_)).w_.IMAG_);(*_194w).eta_ .IMAG_=(_201r_200ibeta*(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_)).u_.IMAG_+_202i_200ibeta*(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_)).u_.REAL_)-(_197r_196ialfa*(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_)).w_.IMAG_+_198i_196ialfa*(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_)).w_.REAL_);(*_194w).eta_ .REAL_=temp;};
     }iz_++;}while(iz_<=dnsdata_102h);}ix_--;}while(ix_>=0);}
      {int _203i_=dnsdata_86h;do{{if((ssize_t)sizeof(struct VETA_)==(ssize_t)sizeof(struct VETA_)&&(ssize_t)sizeof(struct VETA_)==(ssize_t)sizeof(struct VETA_)){if(!(fseeko(diskfield_,_203i_*(off_t)dnsdata_89i+iy_*(off_t)dnsdata_90i+(off_t)((((ssize_t)sizeof(struct dnsdata_s91)+dnsdata_92i)+dnsdata_92i)-dnsdata_98st+(ssize_t)(char*)(struct dnsdata_s91*)(0))+dnsdata_97st,SEEK_SET)==0&&fwrite(_203i_*dnsdata_103i+fieldbuf_+dnsdata_97st,(ssize_t)sizeof(struct VETA_),dnsdata_88h-dnsdata_87l+1,diskfield_)==dnsdata_88h-dnsdata_87l+1))ioerr(diskfield_);}else{  {int _204i_=dnsdata_87l;do{{if(!(fseeko(diskfield_,_204i_*(off_t)(ssize_t)sizeof(struct VETA_)+_203i_*(off_t)dnsdata_89i+iy_*(off_t)dnsdata_90i+(off_t)((((ssize_t)sizeof(struct dnsdata_s91)+dnsdata_92i)+dnsdata_92i)-dnsdata_98st+(ssize_t)(char*)(struct dnsdata_s91*)(0)),SEEK_SET)==0&&fwrite((struct VETA_*)(_204i_*(ssize_t)sizeof(struct VETA_)+_203i_*dnsdata_103i+fieldbuf_),(ssize_t)sizeof(struct VETA_),1,diskfield_)==1))ioerr(diskfield_);}_204i_++;}while(_204i_<=dnsdata_88h);}};}_203i_--;}while(_203i_>=0);}
iy_+=1;};}

  errfclose(&diskfield_);
  if( !(next_==NULL) ){  putc('\n', next_);};
    {int iy_=(dnsdata_4nyl-2);do{{ { struct VELOCITY_ *_205w;
_205w=(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+V_);
{register double temp=(*_205w).u_.REAL_+u_conv_;(*_205w).u_.IMAG_=(*_205w).u_.IMAG_;(*_205w).u_.REAL_=temp;}; {register double temp=(*_205w).w_.REAL_+w_conv_;(*_205w).w_.IMAG_=(*_205w).w_.IMAG_;(*_205w).w_.REAL_=temp;};}}iy_++;}while(iy_<=(dnsdata_5nyh+2));}
}freemem(es);};
}}
    
void dnsdata_113read_restart_file(){{struct freefunc* es=freestack;
if( restart_file_[0]==0 ){
  time_=0.;  memset(dnsdata_52st+V_,0,dnsdata_50i);
  if( (next_==NULL) ){  {int iy_=(dnsdata_5nyh+2)-10  ;while(iy_<=(dnsdata_5nyh+2)){
      {int ix_=dnsdata_45h;do{{int iz_=dnsdata_46l;do{{ { struct VELOCITY_ *_114w;
double _115r;
struct COMPLEX_ _116;
double _117r;
struct COMPLEX_ _118;
double _119r;
struct COMPLEX_ _120;
_114w=(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+ix_*dnsdata_49i+V_);
_115r=((double)(rand())/2147483647.)*2.*3.14159265358979323846;
complex_2EXP(&_116,0.,_115r);{register double temp=(0.0001*_116.REAL_);(*_114w).u_.IMAG_=(0.0001*_116.IMAG_);(*_114w).u_.REAL_=temp;}; _117r=((double)(rand())/2147483647.)*2.*3.14159265358979323846;
complex_2EXP(&_118,0.,_117r);{register double temp=(0.0001*_118.REAL_);(*_114w).v_.IMAG_=(0.0001*_118.IMAG_);(*_114w).v_.REAL_=temp;}; _119r=((double)(rand())/2147483647.)*2.*3.14159265358979323846;
complex_2EXP(&_120,0.,_119r);{register double temp=(0.0001*_120.REAL_);(*_114w).w_.IMAG_=(0.0001*_120.IMAG_);(*_114w).w_.REAL_=temp;};}}iz_++;}while(iz_<=dnsdata_47h);}ix_--;}while(ix_>=0);}
     {int iz_=1  ;do{{ {register double temp=(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+V_)).u_.REAL_;(*(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(-iz_)*dnsdata_48i+V_)).u_.IMAG_=-((*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+V_)).u_.IMAG_);(*(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(-iz_)*dnsdata_48i+V_)).u_.REAL_=temp;}; {register double temp=(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+V_)).v_.REAL_;(*(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(-iz_)*dnsdata_48i+V_)).v_.IMAG_=-((*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+V_)).v_.IMAG_);(*(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(-iz_)*dnsdata_48i+V_)).v_.REAL_=temp;}; {register double temp=(*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+V_)).w_.REAL_;(*(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(-iz_)*dnsdata_48i+V_)).w_.IMAG_=-((*(struct VELOCITY_*)(iy_*(ssize_t)sizeof(struct VELOCITY_)+iz_*dnsdata_48i+V_)).w_.IMAG_) ;(*(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+(-iz_)*dnsdata_48i+V_)).w_.REAL_=temp;};}iz_+=1;}while(iz_<=nz_);}
  iy_+=1;};}};
   {int iy_=(dnsdata_4nyl-2)  ;do{{ { struct VELOCITY_ *_121w;
_121w=(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+V_);
(*_121w).u_.REAL_=3./4.*(1.-pow((1.-(*(double *)(iy_*(ssize_t)sizeof(double)+y_))),2)); (*_121w).u_.IMAG_=0.; memset(&(*_121w).v_,0,(ssize_t)sizeof(struct COMPLEX_)); (*_121w).w_.IMAG_=0.;}}iy_+=1;}while(iy_<=(dnsdata_5nyh+2));}
}else{
  if( (next_==NULL) ){  fprintf(stdout,"""Reading from restart_file: ""\t%s" ,restart_file_);putc('\n',stdout);};
   errfopen(&diskimage_ ,restart_file_,O_RDWR|O_CREAT);  {
    if( time_from_restart_ ){
         if(!(scanrec( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_)," ny = %d",&ny_)>0&&scanrec( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_)," nx = %d",&nx_)>0&&scanrec( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_)," nz = %d",&nz_)>0&&scanrec( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_)," alfa0 = %lg",&alfa0_)>0&&scanrec( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_)," beta0 = %lg",&beta0_)>0&&scanrec( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_)," ymin = %lg",&ymin_)>0&&scanrec( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_)," ymax = %lg",&ymax_)>0&&scanrec( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_)," a = %lg",&a_)>0&&scanrec( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_)," ni = %lg",&ni_)>0&&scanrec( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_)," time = %lg",&time_)>0))ioerr( (fseeko(diskimage_,(-(0))+(ssize_t)(*(struct dnsdata_s78 *)(0)).header_ ,SEEK_SET),diskimage_));  ni_=1./ni_;
      if( (next_==NULL) ){  fprintf(stdout,"""Starting at non-zero time=""%g",time_);putc('\n',stdout);};
    };
     {int iy_=  dnsdata_4nyl-2  ;while(iy_<=dnsdata_5nyh+2){
         {int _122i_=dnsdata_45h;do{{ssize_t _123st;
_123st=dnsdata_46l*(ssize_t)sizeof(struct VELOCITY_);
if(dnsdata_48i==(ssize_t)sizeof(struct VELOCITY_)&&(ssize_t)sizeof(struct VELOCITY_)==(ssize_t)sizeof(struct VELOCITY_)){if(!(fseeko(diskimage_,_122i_*(off_t)dnsdata_76i+iy_*(off_t)dnsdata_77i+(off_t)((ssize_t)sizeof(struct dnsdata_s78)-dnsdata_83st+(ssize_t)(char*)(struct dnsdata_s78*)(0))+_123st,SEEK_SET)==0&&fread(_122i_*dnsdata_49i+iy_*(ssize_t)sizeof(struct VELOCITY_)+V_+_123st,(ssize_t)sizeof(struct VELOCITY_),dnsdata_47h-dnsdata_46l+1,diskimage_)==dnsdata_47h-dnsdata_46l+1))ioerr(diskimage_);}else{  {int _124i_=dnsdata_46l;do{{if(!(fseeko(diskimage_,_124i_*(off_t)(ssize_t)sizeof(struct VELOCITY_)+_122i_*(off_t)dnsdata_76i+iy_*(off_t)dnsdata_77i+(off_t)((ssize_t)sizeof(struct dnsdata_s78)-dnsdata_83st+(ssize_t)(char*)(struct dnsdata_s78*)(0)) ,SEEK_SET)==0&&fread((struct VELOCITY_ *)(_124i_*dnsdata_48i+_122i_*dnsdata_49i+iy_*(ssize_t)sizeof(struct VELOCITY_)+V_),(ssize_t)sizeof(struct VELOCITY_),1,diskimage_)==1))ioerr(diskimage_);}_124i_++;}while(_124i_<=dnsdata_47h);}};}_122i_--;}while(_122i_>=0);}
iy_+=1;};}
  errfclose(&diskimage_);
}};
  {int iy_=(dnsdata_4nyl-2);do{{ { struct VELOCITY_ *_125w;
_125w=(struct VELOCITY_ *)(iy_*(ssize_t)sizeof(struct VELOCITY_)+V_);
{register double temp=(*_125w).u_.REAL_+u_conv_;(*_125w).u_.IMAG_=(*_125w).u_.IMAG_;(*_125w).u_.REAL_=temp;}; {register double temp=(*_125w).w_.REAL_+w_conv_;(*_125w).w_.IMAG_=(*_125w).w_.IMAG_;(*_125w).w_.REAL_=temp;};}}iy_++;}while(iy_<=(dnsdata_5nyh+2));}
}}

void dnsdata_114simple(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG){{struct freefunc* es=freestack;
  double _115r;
_115r=(1./(deltat_));
{register double temp=(unkn_REAL*_115r)+expl_REAL;(*rhs_).IMAG_=(unkn_IMAG*_115r)+expl_IMAG;(*rhs_).REAL_=temp;};
}}


void dnsdata_115CN_AB(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG){{struct freefunc* es=freestack;
  double _116r;
_116r=2./deltat_;
{register double temp=(_116r*unkn_REAL)+impl_REAL+(3.*expl_REAL)-((*(struct COMPLEX_*)(old_i+old__)).REAL_);(*rhs_).IMAG_=(_116r*unkn_IMAG)+impl_IMAG+(3.*expl_IMAG)-((*(struct COMPLEX_*)(old_i+old__)).IMAG_);(*rhs_).REAL_=temp;};
  {register double temp=expl_REAL;(*(struct COMPLEX_ *)(old_i+old__)).IMAG_=expl_IMAG;(*(struct COMPLEX_ *)(old_i+old__)).REAL_=temp;};
}}


void dnsdata_116RK1_rai(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG){{struct freefunc* es=freestack;
  double _117r;
_117r=120./32./deltat_;
{register double temp=(_117r*unkn_REAL)+impl_REAL+(2.*expl_REAL);(*rhs_).IMAG_=(_117r*unkn_IMAG)+impl_IMAG+(2.*expl_IMAG);(*rhs_).REAL_=temp;};
  {register double temp=expl_REAL;(*(struct COMPLEX_ *)(old_i+old__)).IMAG_=expl_IMAG;(*(struct COMPLEX_ *)(old_i+old__)).REAL_=temp;};
}}
double dnsdata_117RK1_rai_coeff;


void dnsdata_118RK2_rai(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG){{struct freefunc* es=freestack;
  double _119r;
double _120r;
double _121r;
_119r=120./(8.*deltat_);
_120r=50./8.;
_121r=34./8.;
{register double temp=(_119r*unkn_REAL)+impl_REAL+(_120r*expl_REAL)-(_121r*(*(struct COMPLEX_*)(old_i+old__)).REAL_);(*rhs_).IMAG_=(_119r*unkn_IMAG)+impl_IMAG+(_120r*expl_IMAG)-(_121r*(*(struct COMPLEX_*)(old_i+old__)).IMAG_);(*rhs_).REAL_=temp;};
  {register double temp=expl_REAL;(*(struct COMPLEX_ *)(old_i+old__)).IMAG_=expl_IMAG;(*(struct COMPLEX_ *)(old_i+old__)).REAL_=temp;};
}}
double dnsdata_119RK2_rai_coeff;


void dnsdata_120RK3_rai(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG){{struct freefunc* es=freestack;
  double _121r;
double _122r;
double _123r;
_121r=120./(20.*deltat_);
_122r=90./20.;
_123r=50./20.;
{register double temp=(_121r*unkn_REAL)+impl_REAL+(_122r*expl_REAL)-(_123r*(*(struct COMPLEX_*)(old_i+old__)).REAL_);(*rhs_).IMAG_=(_121r*unkn_IMAG)+impl_IMAG+(_122r*expl_IMAG)-(_123r*(*(struct COMPLEX_*)(old_i+old__)).IMAG_);(*rhs_).REAL_=temp;};
}}
double dnsdata_121RK3_rai_coeff;


void dnsdata_122RK1_kom(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG){{struct freefunc* es=freestack;
  double _123r;
_123r=1020./240./deltat_;
{register double temp=(_123r*unkn_REAL)+impl_REAL+(2.*expl_REAL);(*rhs_).IMAG_=(_123r*unkn_IMAG)+impl_IMAG+(2.*expl_IMAG);(*rhs_).REAL_=temp;};
  {register double temp=expl_REAL;(*(struct COMPLEX_ *)(old_i+old__)).IMAG_=expl_IMAG;(*(struct COMPLEX_ *)(old_i+old__)).REAL_=temp;};
}}
double dnsdata_123RK1_kom_coeff;


void dnsdata_124RK2_kom(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG){{struct freefunc* es=freestack;
  double _125r;
double _126r;
double _127r;
_125r=1020./(32.*deltat_);
_126r=289./32.;
_127r=225./32.;
{register double temp=(_125r*unkn_REAL)+impl_REAL+(_126r*expl_REAL)-(_127r*(*(struct COMPLEX_*)(old_i+old__)).REAL_);(*rhs_).IMAG_=(_125r*unkn_IMAG)+impl_IMAG+(_126r*expl_IMAG)-(_127r*(*(struct COMPLEX_*)(old_i+old__)).IMAG_);(*rhs_).REAL_=temp;};
  {register double temp=expl_REAL;(*(struct COMPLEX_ *)(old_i+old__)).IMAG_=expl_IMAG;(*(struct COMPLEX_ *)(old_i+old__)).REAL_=temp;};
}}
double dnsdata_125RK2_kom_coeff;


void dnsdata_126RK3_kom(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG){{struct freefunc* es=freestack;
  double _127r;
double _128r;
double _129r;
_127r=1020./(68.*deltat_);
_128r=25./4.;
_129r=17./4.;
{register double temp=(_127r*unkn_REAL)+impl_REAL+(_128r*expl_REAL)-(_129r*(*(struct COMPLEX_*)(old_i+old__)).REAL_);(*rhs_).IMAG_=(_127r*unkn_IMAG)+impl_IMAG+(_128r*expl_IMAG)-(_129r*(*(struct COMPLEX_*)(old_i+old__)).IMAG_);(*rhs_).REAL_=temp;};
  {register double temp=expl_REAL;(*(struct COMPLEX_ *)(old_i+old__)).IMAG_=expl_IMAG;(*(struct COMPLEX_ *)(old_i+old__)).REAL_=temp;};
}}
double dnsdata_127RK3_kom_coeff;


void dnsdata_128RK4_kom(struct COMPLEX_ *rhs_,const int old_l,const int old_h,const ssize_t old_i,char *old__,double unkn_REAL,double unkn_IMAG,double impl_REAL,double impl_IMAG,double expl_REAL,double expl_IMAG){{struct freefunc* es=freestack;
  double _129r;
double _130r;
double _131r;
_129r=1020./(170.*deltat_);
_130r=9./2.;
_131r=5./2.;
{register double temp=(_129r*unkn_REAL)+impl_REAL+(_130r*expl_REAL)-(_131r*(*(struct COMPLEX_*)(old_i+old__)).REAL_);(*rhs_).IMAG_=(_129r*unkn_IMAG)+impl_IMAG+(_130r*expl_IMAG)-(_131r*(*(struct COMPLEX_*)(old_i+old__)).IMAG_);(*rhs_).REAL_=temp;};
}}
double dnsdata_129RK4_kom_coeff;

