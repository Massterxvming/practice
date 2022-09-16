using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp2
{
    class 成绩
    {
        public string Grade(int n)
        {
            switch (n / 10)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:return "C";break;
                case 7:
                case 8: return "B"; break;
                case 9:
                case 10:return "A";break;
            }
            return null;
        }
    }
}
