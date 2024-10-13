import java.util.*;

class a
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numStores = input.nextInt();


        StringBuilder result = new StringBuilder();
        while (numStores > 0)
        {
            int coinSize = input.nextInt();
            int numFitbits = input.nextInt();
            StringBuilder curStore = new StringBuilder();
            TreeMap<Integer, Integer> coins = new TreeMap<Integer, Integer>();
            long coinSum = 0;

            for (int i = 0; i < coinSize; i++)
            {
                int k = input.nextInt();
                coins.put(k, coins.getOrDefault(k, 0) + 1);
                coinSum += k;
            }
            
            while (numFitbits > 0)
            {
                int fitbit = input.nextInt();
                TreeMap<Integer, Integer> curCoins = new TreeMap<>(coins);
                
                if (!(fitbit > coinSum))
                {
                    while (curCoins.floorKey(fitbit) != null)
                    {
                        
                        int k = curCoins.floorKey(fitbit);
                        fitbit -= k;
                        if (curCoins.get(k) == 1)
                        {
                            curCoins.remove(k);
                        }
                        else
                        {
                            curCoins.put(k, curCoins.get(k) - 1);
                        }
                    }
                }
                
                if (numFitbits == 1)
                {
                    if (fitbit == 0)
                    {
                        curStore.append("1");
                    }
                    else
                    {
                        curStore.append("0");
                    } 
                }
                else
                {
                    if (fitbit == 0)
                    {
                        curStore.append("1 ");
                    }
                    else
                    {
                        curStore.append("0 ");
                    }
                }

                numFitbits--;
            }

            result.append(curStore).append("\n");
            numStores--;
        }
        System.out.println(result);
    }
}