using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp8
{
    class 完数
    {
        int j, i;
        public void perfect()
        {
            for(i=1;i<=1000;i++)
            {
                int s = 0;
                for(j = 1; j < i; j++)
                {
                    if (i % j == 0) s += j;
                }
                if(s==i)
                Console.Write(s+" ");
            }
        }
    }
}
