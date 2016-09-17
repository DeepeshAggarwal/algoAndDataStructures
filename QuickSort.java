import java.util.Comparator;
import java.util.Random;

public class QuickSort {

    public static int partiotion(Comparable<Item>[] a, Integer low, Integer hi) {
        int i = low;
        int j = hi + 1;
        while (i < j) {

            while (!Item.less(a[low], a[++i]))
                if (i == hi)
                    break;
            while (Item.less(a[low], a[--j])) {
                if (j == low)
                    break;
            }
            if (i < j) {
                Item.swap(a, i, j);
            }
        }
        Item.swap(a, low, j);
        return j;
    }

    public static void sort(Comparable<Item>[] a, Integer low, Integer hi) {

        if (low >= hi)
            return;

        int mid = partiotion(a, low, hi);
        // mid - 1 because mid is as it's position already
        sort(a, low, mid - 1);
        sort(a, mid + 1, hi);

    }

    public static int slope(Item item) {
        return 0;
    }

    public static void sort(Comparable<Item>[] a) {
        sort(a, 0, a.length - 1);

    }

    public Comparator sortOrder() {
        return new Comparator<Item>() {

            @Override
            public int compare(Item o1, Item o2) {
                return 0;
            }

        };
    }

    public static void main(String[] args) {
        int i = 11;
        Item[] items = new Item[i];

        Random rn = new Random();
        for (int j = 0; j < i; j++) {
            Item item = new Item(rn.nextInt(100));
            items[j] = item;
            System.out.println(j + ". " + items[j]);
        }
        QuickSort.sort(items);
        System.out.println("\n\n");
        for (int j = 0; j < i; j++) {
            System.out.println(j + ". " + items[j]);
        }

    }

}
