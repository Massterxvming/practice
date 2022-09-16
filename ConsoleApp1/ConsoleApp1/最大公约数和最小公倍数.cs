using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp6
{
    class 最大公约数和最小公倍数
    {
        public int maxi(int n,int m)
        {
            int x = (m > n) ? m:n;
            while (n != 0)
            {
                m = x % n;
                x = n;
                n = m;
            }
            return x;
        }
        public int mini(int n,int m)
        {
            while (n % m != 0)
            {
                n += n;
            }
            return n;
        }
    }
}
