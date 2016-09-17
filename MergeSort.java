import java.util.Random;

public class MergeSort {

    public static void merge(Comparable<Item>[] a, Comparable<Item>[] aux,
            Integer low, Integer mid, Integer hi) {

        // copy from a to aux
        for (int l = low; l <= hi; l++) {
            aux[l] = a[l];
        }
        int i = low;
        int j = mid + 1;

        for (int k = low; k <= hi; k++) {
            if (i > mid) {
                a[k] = aux[j++];
            } else if (j > hi) {
                a[k] = aux[i++];
            } else if (Item.less(aux[i], aux[j])) {
                a[k] = aux[i++];
            } else if (Item.less(aux[j], aux[i])) {
                a[k] = aux[j++];
            }
        }

    }

    public static void sort(Comparable<Item>[] a, Comparable<Item>[] aux,
            Integer low, Integer hi) {

        if (low >= hi)
            return;

        int mid = low + (hi - low) / 2;
        sort(a, aux, low, mid);
        sort(a, aux, mid + 1, hi);
        merge(a, aux, low, mid, hi);
    }

    @SuppressWarnings("unchecked")
    public static void sort(Comparable<Item>[] a) {

        Comparable<Item>[] aux = new Comparable[a.length];
        sort(a, aux, 0, a.length - 1);

    }

    public static void main(String[] args) {
        int i = 11;
        Item[] items = new Item[i];

        Random rn = new Random();
        for (int j = 0; j < i; j++) {
            Item item = new Item(rn.nextInt(100));
            items[j] = item;
        }
        MergeSort.sort(items);
        for (int j = 0; j < i; j++) {
            System.out.println(j + ". " + items[j]);
        }

    }
}
