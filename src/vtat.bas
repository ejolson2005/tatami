module vtat

'    vtat.bas -- Compute T(s) from Project Euler Problem 256
'    Written in Visual Basic November 4, 2019 by Eric Olson
'
'    Based on tatami.c posted by JCYR on the Raspberry Pi forum
'        https://www.raspberrypi.org/forums/
'        viewtopic.php?f=31&t=240287&start=1275#p1560751
'
'    See the analysis by Dean Hickerson for more information
'        http://oeis.org/A068920/a068920.txt

dim T() as byte
dim smax,imax as integer

sub Tinit(n as integer)
    smax=n:imax=Math.Sqrt(n)+0.5
    redim T(smax)
    dim i as integer
    for i=1 to imax
        dim jmin,jmax as integer
        jmin=i+3:jmax=2*i-4
        while i*jmin<=smax and jmin<=jmax
            dim j as integer
            for j=jmin to jmax
                if i*j<=smax then
                    T(i*j)=T(i*j)+1
                end if
            next j
            jmin=jmin+i+1:jmax=jmax+i-1
        end while    
    next i
end sub

function Tinv(n as integer) as integer
    dim s as integer
    for s=2 to smax step 2
        if T(s)=n then
            return s
        end if
    next s
    return -1
end function

function main() as integer
    tinit(100000000)
    console.writeline("T({0:D})=200",Tinv(200))
    return 0
end function

end module 
