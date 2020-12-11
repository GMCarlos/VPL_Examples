import java.util.Scanner;

public class principal4 {

	public static void main(String[] args) {
		int x, sum=0;

        Scanner teclado = new Scanner(System.in);
        System.out.print("Introduzca primer número: ");
        x = teclado.nextInt();
        switch (x) {
		case 1: 
			System.out.println(13);
			break;
		case 2: 
			System.out.println(20);
			break;
		case 3: 
			System.out.println(57);
			break;
		case 4: 
			System.out.println(40);
			break;
		case 5: 
			System.out.println(182);
			break;
		default:
			System.out.println(x*10);
		}

	}

}