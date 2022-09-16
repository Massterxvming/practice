using System;
using System.Collections.Generic;
using System.Text;
namespace ConsoleApp7
{
    class 统计字符个数
    {
        public void statistic()
        {
            char c;
            int[] a=new int[] { 0,0,0,0};
            for (int i = 0; ( c=Convert.ToChar(Console.Read())) != '\n'; i++)
            {
                if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
                {
                    a[0]++;
                }
                else if (c==' ')
                {
                    a[1]++;
                }
                else if (c >= '0' && c <= '9')
                {
                    a[2]++;
                }
                else 
                {
                    a[3]++;
                }
            }
            a[3] -= 1;
            Console.WriteLine("英文字母的个数：" + a[0]);
            Console.WriteLine("空格的个数：" + a[1]);
            Console.WriteLine("数字的个数：" + a[2]);
            Console.WriteLine("其他字符的个数：" + a[3]);
        }

        
    }
}
