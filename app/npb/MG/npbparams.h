c NPROCS = 8 CLASS = D
c  
c  
c  This file is generated automatically by the setparams utility.
c  It sets the number of processors and the class of the NPB
c  in this directory. Do not modify it by hand.
c  
        integer nprocs_compiled
        parameter (nprocs_compiled = 8)
        integer nx_default, ny_default, nz_default
        parameter (nx_default=1024, ny_default=1024, nz_default=1024)
        integer nit_default, lm, lt_default
        parameter (nit_default=50, lm = 9, lt_default=10)
        integer debug_default
        parameter (debug_default=0)
        integer ndim1, ndim2, ndim3
        parameter (ndim1 = 9, ndim2 = 9, ndim3 = 9)
        logical  convertdouble
        parameter (convertdouble = .false.)
        character*11 compiletime
        parameter (compiletime='30 Jan 2021')
        character*5 npbversion
        parameter (npbversion='3.3.1')
        character*6 cs1
        parameter (cs1='mpif77')
        character*9 cs2
        parameter (cs2='$(MPIF77)')
        character*39 cs3
        parameter (cs3='-L/home/sunjw/mpiP/mpiP/lib -lmpiP -lm ')
        character*46 cs4
        parameter (cs4='-I/home/sunjw/OpenMPI/openmpi-3.1.6-bin/inc...')
        character*18 cs5
        parameter (cs5='-O -mcmodel=medium')
        character*18 cs6
        parameter (cs6='-O -mcmodel=medium')
        character*6 cs7
        parameter (cs7='randi8')
