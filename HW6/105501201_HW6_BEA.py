
n = int(input())
O = []

for i in range(n):

    a = input()

    index = 0
    for i in range( len(a) ):
        if a[i] == " ":
            index = i
            break
    exp1 = int( a[0:index] )
    exp2 = int( a[index+1:len(a)] )

    #print( "exp1=", exp1 )
    #print( "exp2=" , exp2 )

    result1 = 1
    result2 = 1
    
    ref1 = 2
    while exp1 > 0:
        r = exp1 % 2
        exp1 = exp1 >> 1
        #print(exp1)

        if r == 1 :
            result1 = result1 * ref1
        
        ref1 = ref1 ** 2
        
    ref2 = 2
    while exp2 > 0:
        r = exp2 % 2
        exp2 = exp2 >> 1
        #print(exp2)

        if r == 1 :
            result2 = result2 * ref2
        
        ref2 = ref2 ** 2
    O.append( result1 + result2 )


for i in range( len(O) ):
    print( O[i] )

    

    