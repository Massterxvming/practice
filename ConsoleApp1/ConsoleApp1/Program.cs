using System;
using ConsoleApp5;
using ConsoleApp2;
using ConsoleApp3;
using ConsoleApp4;
using ConsoleApp6;
using ConsoleApp8;
using ConsoleApp7;
using ConsoleApp9;
using ConsoleApp10;
namespace ConsoleApp1
{
    
    class Program
    {
        public _1234排列 pl = new _1234排列();
        public 反弹高度 H = new 反弹高度();
        public 完数 ws = new 完数();
        public 统计字符个数 tj = new 统计字符个数();
        public 最大公约数和最小公倍数 zz = new 最大公约数和最小公倍数();
        public 素数 s=new 素数();
        public 水仙花数 shui=new 水仙花数();
        public 分解质因数 divide= new 分解质因数();
        public 成绩 cj = new 成绩();
        public static int Fe(int n)
        {
            if (n == 1) return 1;
            if (n == 2) return 1;
            else return Fe(n - 1) + Fe(n - 2);

        }
        //斐波那契数列
        static void Main(string[] args)
        {
            Program P=new Program();
            P.pl.select();
        }
        
    }
}
