#if defined (A) || defined (B)

class Computer:public bar
    
{
if ( i > 0 ) 
{
    x = i;   
}
else if( i < 0)
    x = q;

else
#if defined (A)
 
    x=j;
    #endif
    #if defined(B)
       x = s;
    #endif
 

}



#endif
