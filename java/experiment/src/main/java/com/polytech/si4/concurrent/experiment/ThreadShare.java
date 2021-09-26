package com.polytech.si4.concurrent.experiment;

public class ThreadShare {
	static int myvar = 1;
	public static void shareVare() {
	System.out.println("[parent] Value of myvar: " + myvar);
	Thread thread = new Thread(){
	    public void run(){
	      System.out.println("Thread Running");
	      myvar++;
	      System.out.println("[child] Value of myvar: " + myvar);
	    }
	  };

	  thread.start();
	  try {
		thread.join();
	} catch (InterruptedException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	  System.out.println("[parent] Value of myvar: " + myvar);
}

}
