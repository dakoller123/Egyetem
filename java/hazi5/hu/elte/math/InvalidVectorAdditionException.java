package hu.elte.math;

public class InvalidVectorAdditionException extends RuntimeException {

	public InvalidVectorAdditionException(String errorMessage) {
        super(errorMessage);
    }
}