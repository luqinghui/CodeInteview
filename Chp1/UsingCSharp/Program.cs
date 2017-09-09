using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UsingCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            AlgorithmOneOne();


        }

        private static void AlgorithmOneThree(char[] str1, char[] str2)
        {
            
        }

        private static bool IsSame(char[] str1, char[] str2)
        {
            //if (str1.Length != str2.Length) return false;

            //foreach(char c in str1)

        }






        private static void AlgorithmOneOne()
        {
            //method 1
            //string str1 = "ABCDEFA";

            //if (IsAllDifferentWithHash(str1))
            //    Console.WriteLine("全部不同");
            //else
            //    Console.WriteLine("不是全部不同");

            //method 2
            //string str1 = "ABCDEFA";
            //if (IsAllDifferent(str1.ToCharArray()))
            //    Console.WriteLine("全部不同");
            //else
            //    Console.WriteLine("不是全部不同");

        }

        //利用散列表实现
        private static bool IsAllDifferentWithHash(string str1)
        {
            HashSet<char> hash = new HashSet<char>();

            foreach(var c in str1)
            {
                if (!hash.Contains(c))
                    hash.Add(c);
                else return false;
            }

            return true;
        }

        //利用排序实现
        private static bool IsAllDifferent(char[] str1)
        {
            for(int i = 1; i< str1.Length; i++)
            {
                for (int j = i; j > 0; j--)
                {
                    if (str1[j] < str1[j - 1])
                    {
                        char t = str1[j];
                        str1[j] = str1[j - 1];
                        str1[j - 1] = t;
                    }
                    else
                        break;
                }
            }

            for(int i=0;i<str1.Length-1;i++)
            {
                if (str1[i] == str1[i + 1])
                    return false;
            }
            return true;
        }
    }
}
