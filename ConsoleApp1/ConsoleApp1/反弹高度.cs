using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp9
{
    class 反弹高度
    {
        double High = 0,lasth;
        public void high(double n)
        {
            for (int i = 1; i<=10;i++)
            {
                if (i == 1) High += n;
                else High += 2 * n;
                n /= 2.0;
            }
            lasth = n;
            Console.WriteLine("移动距离为：" + High);
            Console.WriteLine("最后一次高度为：" + lasth);
        }
    }
}
