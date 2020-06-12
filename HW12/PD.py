
n = int( input() )

L = []
for i in range( n ):
    a = int( input() )
    
    if a == 1:
        L.append( 1 )
        continue
    
    j = 9
    sum = 0
    p = 1
    while j > 1 :
        if a%j == 0:
            a = a / j
            sum = sum + j*p
            p = p * 10
        else:
            j = j - 1
    if a == 1:
        L.append( sum )
    else:
        L.append( -1 )

for i in range( len( L ) ):
    print( L[i] )