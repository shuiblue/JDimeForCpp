#if defined (A) || defined (B)

class Computer:public bar
    
{
if ( i > 0 ) 
{
    x = i;   
}
else if( i < 0)
    x = q;

#if defined (A)
else 
    x=j;
    #endif
    #if defined(B)
else 
       x = s;
    #endif
 

}



#endif