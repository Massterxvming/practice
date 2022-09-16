using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp5
{
    class 素数
    {
        public  bool judge(int n)
        {
            for(int i = 2; i < n; i++)
            {
                if (n % i == 0) return false;
            }
            return true;
        }
    }
}
