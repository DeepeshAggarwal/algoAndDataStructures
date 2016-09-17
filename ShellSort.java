import java.util.Scanner;

public class ShellSort {

    public void sort(Comparable[] points, int loop) {

        int h = 1;
        while (h < points.length / 3)
            h = 3 * h + 1;

        while (h >= 1) {
            System.out.println(h);
            for (int i = 0; i < points.length - h; i++) {
                if (less(points[i], points[i + h])) {
                    exchng(points, i, i + h);
                }
            }
            h = h / 3;
        }
    }

    @SuppressWarnings("rawtypes")
    private void exchng(Comparable[] comparable, int i, int j) {
        Comparable temp = comparable[i];
        comparable[i] = comparable[j];
        comparable[j] = temp;
    }

    @SuppressWarnings({ "rawtypes", "unchecked" })
    private boolean less(Comparable comparable, Comparable comparable2) {
        return comparable.compareTo(comparable2) < 0;
    }

    public static void main(String[] args) {
        int i = 10;
        Integer[] points = new Integer[i];
        Scanner sc = new Scanner(System.in);
        for (int j = 0; j < i; j++) {
            points[j] = sc.nextInt();
        }
        int loop = sc.nextInt();
        SelectionSort sort = new SelectionSort();
        sort.sort(points, loop);
        for (int j = 0; j < points.length; j++) {
            System.out.print(points[j] + " ");
        }
        sc.close();
        // System.out.println(+" " + b.segments());
    }

}
