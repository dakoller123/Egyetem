package hu.elte.javagyak.library.tests;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;
import hu.elte.javagyak.library.tests.BookTests;

public class TestRunner {
   public static void main(String[] args) {
      Result result = JUnitCore.runClasses(BookTests.class);
		
      for (Failure failure : result.getFailures()) {
         System.out.println(failure.toString());
      }
		
      System.out.println(result.wasSuccessful());
   }
}  