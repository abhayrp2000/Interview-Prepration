public class knapsack {
    public static void main(String[] args) {
        int[] wt = {1,3,4,5};
        int[] val = {1,4,5,7};
        int w = 7;
        int n = 4;
        System.out.println(knap(wt, val, w, n));

    }
    public static int knap(int[] wt, int[] val, int w, int n){
        if (n == 0 || w == 0)
            return 0;
        if (wt[n-1] <= w)
            return Math.max((val[n-1] + knap(wt, val, w-wt[n-1], n-1)), (knap(wt, val, w, n-1)));
        if (wt[n-1] > w)
            return knap(wt, val, w, n-1);
        return w;
    }
}
