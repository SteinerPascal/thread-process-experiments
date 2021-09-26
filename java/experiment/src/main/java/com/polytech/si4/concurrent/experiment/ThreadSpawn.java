package com.polytech.si4.concurrent.experiment;

public class ThreadSpawn {
	static int myvar = 1;
	public static void createThreads() {
		
		long start = System.currentTimeMillis();
		int loops = 1000;
		
		for(int i = 0; i< 1000; i++) {
			Thread thread = new Thread(){
			    public void run(){
			      System.out.println("Thread Running");
			    }
			  };

			  thread.start();
			  try {
				thread.join();
				System.out.println("Thread stopped");
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		long finish = System.currentTimeMillis();
		double timeElapsed =(double) (finish - start) /1000;
		System.out.println("total time used: " + timeElapsed);
		double timeperproc = (double) (timeElapsed / loops);
		System.out.println("time per process: " + timeperproc);
	}
}
