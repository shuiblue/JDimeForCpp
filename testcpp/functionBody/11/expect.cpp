#if defined (A) || defined (B)
void a(){
while(i>=0){
#if defined (A)
 string1[i] = string2[i];
#endif
#if defined (B)
   string1[j] = string2[j];
 #endif
 }
}
#endif
