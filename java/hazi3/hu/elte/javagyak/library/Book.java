package hu.elte.javagyak.library;

public class Book{
	
	private String title;
	private String author;
	private int	publicationDate;
	private boolean available;
	
	public String getTitle(){
		//Question: String is immutable, so no cloning needed, right?
		return title;
	}
	
	public String getAuthor(){
		return author;
	}
	
	public int getPublicationDate(){
		return publicationDate;
	}
	
	public boolean isAvailable(){
		return available;
	}
	
	public void setUnavailable(){
		available = false;
	}
	
	public void setAvailable(){
		available = true;
	}
	
	@Override
	public String toString(){
		return title + " by " + author + ", publicationDate: " + publicationDate + ", Status: " + (available ? "" : "not ") + "available";
	}
	
	public Book(String title, String author, int publicationDate, boolean available){
		super();
		
		if (title == null || title.isEmpty()){
			throw new IllegalArgumentException("parameter name: title value : " + title);
		}
		
		if (author == null || author.isEmpty()){
			throw new IllegalArgumentException("parameter name: author value : " + author);
		}
		
		if (publicationDate < 0){
			throw new IllegalArgumentException("publicationDate is below zero. value: " + publicationDate);
		}
		
		this.title = title;
		this.author = author;
		this.publicationDate = publicationDate;
		this.available = available;
	}
}