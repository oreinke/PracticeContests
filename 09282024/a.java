import java.util.*;

public class a {
    public static void main(String args[]) {
        HashMap<Character, Integer> mappings = new HashMap<>();

        mappings.put('0', 0);
        mappings.put('1', 1);
        mappings.put('2', 2);
        mappings.put('3', 3);
        mappings.put('4', 4);
        mappings.put('5', 5);
        mappings.put('6', 6);
        mappings.put('7', 7);
        mappings.put('8', 8);
        mappings.put('9', 9);
        mappings.put('a', 10);
        mappings.put('b', 11);
        mappings.put('c', 12);
        mappings.put('d', 13);
        mappings.put('e', 14);
        mappings.put('f', 15);
        mappings.put('g', 16);
        mappings.put('h', 17);
        mappings.put('i', 18);
        mappings.put('j', 19);
        mappings.put('k', 20);
        mappings.put('l', 21);
        mappings.put('m', 22);
        mappings.put('n', 23);
        mappings.put('o', 24);
        mappings.put('p', 25);
        mappings.put('q', 26);
        mappings.put('r', 27);
        mappings.put('s', 28);
        mappings.put('t', 29);
        mappings.put('u', 30);
        mappings.put('v', 31);
        mappings.put('w', 32);
        mappings.put('x', 33);
        mappings.put('y', 34);
        mappings.put('z', 35);
        
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        input.nextLine();

        while (numCases > 0)
        {
            String[] words = input.nextLine().split(" ");
            
            int biggestChar = -1;
            boolean zeroFound = false;
            for (int i = 0; i < 5; i++)
            {
                if (i == 1 || i == 3)
                {
                    continue;
                }

                for (char  c : words[i].toCharArray())
                {
                    if (mappings.get(c) > biggestChar)
                    {
                        biggestChar = mappings.get(c);
                    }
                    if (mappings.get(c) == 0)
                    {
                        zeroFound = true;
                    }
                }
            }

            if (biggestChar == 1 && !zeroFound)
            {
                biggestChar--;
            }

            boolean noBaseFound = true;
            for (int i = biggestChar + 1; i < 37; i++)
            {
                long num1 = toDecimal(words[0].toCharArray(), i, mappings);
                long num2 = toDecimal(words[2].toCharArray(), i, mappings);
                long num3 = toDecimal(words[4].toCharArray(), i, mappings);

                if (num1 > 0 && num2 > 0 && num3 > 0)
                {
                    char base = '.';
                    if (i < 10)
                    {
                        base = (char) ('0' + i);
                    }
                    else if (i == 36)
                    {
                        base = '0';
                    }
                    else
                    {
                        base = (char) ('a' + (i - 10));
                    }

                    if (words[1].equals("+"))
                    {
                        if (num1 + num2 == num3)
                        {
                            noBaseFound = false;
                            System.out.print(base);
                        }
                    }
                    else if (words[1].equals("-"))
                    {
                        // System.out.print("\nreached, base: " + base + ", num 1 = " + num1 + ", num2 = " + num2 + ", num3 = " + num3);
                        if (num1 - num2 == num3)
                        {
                            noBaseFound = false;
                            System.out.print(base);
                        }
                    }
                    else if (words[1].equals("*"))
                    {
                        if (num1 * num2 == num3)
                        {
                            noBaseFound = false;
                            System.out.print(base);
                        }
                    }
                    else
                    {
                        if (num1 / num2 == num3 && num1 % num2 == 0)
                        {
                            noBaseFound = false;
                            System.out.print(base);
                        }
                    }
                }
            }

            if (noBaseFound)
            {
                System.out.print("invalid");
            }
            System.out.println();

            numCases--;
        }



    }

    public static long toDecimal (char[] num, int base, HashMap<Character, Integer> mappings)
    {
        long limit = (long) Math.pow(2, 32) - 1;
        int count = 0;
        long result = 0;

        for (int i = num.length - 1; i >= 0; i--)
        {
            result += mappings.get(num[i]) * Math.pow(base, count);

            if (result > limit || result < 0)
            {
                return -1;
            }

            count++;
        }
        
        return result;
    }
}
