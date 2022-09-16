using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp10
{
    class _1234排列
    {
        public void select()
        {
            for(int i = 1; i <= 4; i++)
            {
                for(int j = 1; j <= 4; j++)
                {
                    if (j == i) continue;
                    for(int z = 1; z <= 4; z++)
                    {
                        if (j == i||j==z||i==z) continue;
                        if (i != j && i != z && j != z) Console.WriteLine(i+j.ToString()+z.ToString());
                    }
                }
            }
        }
    }
}
