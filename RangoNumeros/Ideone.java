import java.util.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone {
	public static double getRandom(Double valorMinimo, Double valorMaximo) {
		Random rand = new Random();
		return valorMinimo + (valorMaximo - valorMinimo) * rand.nextDouble();
	}

	public static void main(String[] args) throws java.lang.Exception {
		int numero = 0;
		Scanner reader = new Scanner(System.in);
		numero = reader.nextInt();
		if(numero == 4) {
			System.out.println(String.valueOf(getRandom(4.0, 6.0)));
		}
		

	}

}