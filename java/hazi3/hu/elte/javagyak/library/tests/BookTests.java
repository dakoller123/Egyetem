package hu.elte.javagyak.library.tests;

import org.junit.Test;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertEquals;
import hu.elte.javagyak.library.Book;

public class BookTests {   
	
	String title = "this is a title";
	String author = "this is the author";
	int publicationDate = 1993;
	boolean available = false;
	Book book;

	@Test(expected = IllegalArgumentException.class)
	public void ctor_NullChecks_title() {
      book = new Book(null, author, publicationDate, available);
	}
	
	@Test(expected = IllegalArgumentException.class)
	public void ctor_EmptyString_title() {
      book = new Book("", author, publicationDate, available);
	}
	
	@Test(expected = IllegalArgumentException.class)
	public void ctor_NullChecks_author() {
      book = new Book(title, null, publicationDate, available);
	}
	
	@Test(expected = IllegalArgumentException.class)
	public void ctor_DateValidation() {
      book = new Book(title, null, publicationDate, available);
	}
	
	@Test
	public void ctor_Valid() {
      book = new Book(title, author, publicationDate, available);
	  assertNotNull(book);
	}
	
	@Test
	public void settingAvailibility() {
      book = new Book(title, author, publicationDate, false);
	  assertFalse(book.isAvailable());
	  book.setAvailable();
	  assertTrue(book.isAvailable());  
	}
	
	@Test
	public void cantSetTitleWithoutSetter() {
	  String oldTitle = "thisIsTheOldTitle";
      book = new Book(oldTitle, author, publicationDate, available);
	  String titleInAVariable = book.getTitle();
	  titleInAVariable = "notTheOldTitle";
	  assertFalse(titleInAVariable == oldTitle);
	  assertFalse(titleInAVariable == book.getTitle());
	  assertTrue(oldTitle == book.getTitle());
	}
		
	@Test
	public void toStringTest() {
      book = new Book(title, author, publicationDate, false);
	  String bookString = book.toString();
	  assertTrue(bookString.contains(title + " by " + author));
	  assertTrue(bookString.contains("publicationDate: " + publicationDate));
	  assertTrue(bookString.contains("not available"));
	}
}