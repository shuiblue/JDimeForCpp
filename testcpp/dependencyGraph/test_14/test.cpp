
  volatile int babystepsTodo[3]={0,0,0};

  int read_max6675()
{  

  for(uint8_t axis=0;axis<3;axis++)
  {
    int curTodo=babystepsTodo[axis]; //get rid of volatile for performance
   
    if(curTodo>0)
    {
      babystep(axis,/*fwd*/true);
      babystepsTodo[axis]--; //less to do next time
    }
    else
    if(curTodo<0)
    {
      babystep(axis,/*fwd*/false);
      babystepsTodo[axis]++; //less to do next time
    }
  }

}