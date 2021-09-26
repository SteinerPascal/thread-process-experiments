package com.polytech.si4.concurrent.experiment;

/**
 * References 
 * https://www.developer.com/design/understanding-java-process-and-java-processbuilder/
 * https://zetcode.com/java/processbuilder/
 */

public class ProcessSpawn {
	
	public static void createProcesses() {
		try 
        { 
    		long start = System.currentTimeMillis();
    		int loops = 100;
    		for(int i = 0 ; i<loops; i++) {
    			// create a new process
                System.out.println("Creating Process");
                Process proc = new ProcessBuilder().command("cmd").inheritIO().start();
                proc.destroy();
                int exitCode = proc.waitFor();
                System.out.println("exitCode = " + exitCode);
    		}
    		long finish = System.currentTimeMillis();
    		long timeElapsed = (finish - start) ;
    		System.out.println("total time used: " + timeElapsed);
    		long timeperproc = (long) (timeElapsed / loops);
    		System.out.println("time per process: " + timeperproc);
      
        } 
            catch (Exception ex) 
        {
            ex.printStackTrace();
        }
	}

}
