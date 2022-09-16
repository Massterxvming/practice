using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp4
{
    class 水仙花数
    {
        public void slove()
        {
            for(int i = 100; i < 1000; i++)
            {
                double a=Math.Pow(i % 10, 3);
                double b = Math.Pow(i / 10%10, 3);
                double c = Math.Pow(i / 100 , 3);
                if (a + b + c == i) Console.Write(i + " ");
            }
        }

        
    }
}
