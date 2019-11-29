! Based on Tatami.c written by jcyr on Raspberrypi.org forums
program tatami
  implicit none

  integer, parameter :: N_MAX = 100000000
  integer, parameter :: N_MAX_SQRT = sqrt(real(N_MAX))

  integer :: ierror
  integer, dimension(:), allocatable :: v 

  integer :: i, j, k2, k3, k4

  allocate(v(0:N_MAX-1), stat=ierror)
  if (ierror /= 0) then
    print *, 'Could not allocate vector'
    stop
  end if
  
  do i = 7, N_MAX_SQRT - 1, 2
    k2 = i + 3
    k3 = i + i - 4
    do while((k2 <= k3) .and. ((i * k2) < N_MAX))
      k4 = (N_MAX - 1) / i
      if (k3 < k4) k4 = k3
      do j = k2, k4, 2
        v(i*j) = v(i*j) + 1
      end do
      k2 = k2 + i + 1
      k3 = k3 + i - 1
    end do    
  end do

  do i = 8, N_MAX_SQRT - 1, 2
    k2 = i + 3
    k3 = i + i - 4
    do while((k2 <= k3) .and. ((i * k2) < N_MAX))
      k4 = (N_MAX - 1) / i
      if (k3 < k4) k4 = k3
      do j = k2, k4, 1
        v(i*j) = v(i*j) + 1
      end do
      k2 = k2 + i + 1
      k3 = k3 + i - 1
    end do    
  end do
  
  do i = 0, N_MAX - 1, 1
    if (v(i) == 200) exit
  end do
    
  print *, 'The smallest room size s for which T(s) = 200 is:', i
  
  deallocate(v)  
end program tatami
