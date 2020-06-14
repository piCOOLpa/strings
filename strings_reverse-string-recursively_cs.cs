using System;
using System.Runtime.InteropServices;
using System.Text;
namespace stack_stack_implementation_cs
{
    class Program
    {
        public static char[] reverse_string_recursively( char[] sequence , int index)
        {
            // null char array.

            if (index < sequence.Length)
            {
                // recurse only if the string is not null. Atleast one character.

                int index_a = index;
                int index_b = sequence.Length - index_a - 1;
                sequence = reverse_string_recursively(sequence, ++index);
                

                if (index_a > index_b)
                {
                    // swap the characters at the index_a , index_b
                    // in-place swap 
                    char temp = sequence[index_a];
                    sequence[index_a] = sequence[index_b];
                    sequence[index_b] = temp;

                    //s[index_a] = s[index_a];
                    // above assignment gives error as the string is read-only , it cannot be modified once created .
                    // so we must declare a  character array instaed of string.

                }

            }

            return sequence;
        }
        static void Main(string[] args)
        {
            Console.Write("enter a string which needs to be reversed : ");

            string s = Console.ReadLine();
            // abc 

            char[] sequence = s.ToCharArray();
            // [a , b , c]

            sequence = reverse_string_recursively(sequence, 0);
            // ( [a , b , c] ,0)
            

            Console.WriteLine("the original-string : " + s);
            Console.Write("the reverse of the original-string : ");
            foreach( char c in sequence)
            {
                Console.Write(c);
            }

            Console.ReadLine();
        }
    }
}

