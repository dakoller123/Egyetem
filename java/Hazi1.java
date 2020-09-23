public class Hazi1 {
	
	public static void main(String[] args){
		for (var arg : args){
			try{
				int argInt = Integer.parseInt(arg);
				if (argInt < 2){
					System.err.println(arg + " is less than 2 (and not a prime).");
				}
				else if (isPrime(argInt)){
					System.out.println(arg + " is a prime number.");
				}
				else{
					System.out.println(arg + " is not a prime number.");
				}
			}
			catch(Exception ex){
				System.err.println(arg + " is not a valid integer.");
			}
		}
	}
	
	private static boolean isPrime(int source){
		return (source > 1) && ((source == 2) || isPrime(source, 2));
	}
	
	private static boolean isPrime(int source, int i){
		return ((i == source) || ((source / i * i != source) && isPrime(source, i+1)));
	}
}
