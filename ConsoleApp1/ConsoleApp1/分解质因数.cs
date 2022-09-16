using System;
using System.Collections.Generic;
using System.Text;
using ConsoleApp5;
namespace ConsoleApp3
{
    
    class 分解质因数
    {
        public 素数 su = new 素数();
        public void print(int n)
        {
            Console.Write(n + "=");
            while (n != 0)
            {
                for(int i = 2; i <= n; i++)
                {
                    if (n % i == 0&&su.judge(i))
                    {
                        n /= i;
                        if (n != 1)
                            Console.Write(i + "*");
                        else Console.WriteLine(i);
                    }
                }
            }
        }
    }
}
