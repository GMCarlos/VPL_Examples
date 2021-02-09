import java.util.*;



/* Name of the class has to be "Main" only if the class is public. */
class Ideone {
	public static double getRandom(Double valorMinimo, Double valorMaximo) {
		Random rand = new Random();
		//rand.nextDouble()
		//Devuelve un número de punto flotante aleatorio
		//que es mayor o igual que 0,0 y menor que 1,0
		return valorMinimo + (valorMaximo - valorMinimo) * rand.nextDouble();
	}

	public static void main(String[] args) throws java.lang.Exception {
		Double numero = 0.0;
		Scanner reader = new Scanner(System.in);
		numero = reader.nextDouble();
		System.out.println(String.valueOf(getRandom(0.0, numero)));
		

	}

}
