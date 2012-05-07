public class GotoTest{
public static void doSmthg(){
    int a=1;
    int b=1;
    label:
    do { // Labeled dummy loop
         //if is given has an example, it can be any thing else
for(int j=0;j<100;j++	){
		for(int i=0;i<10;i++){
            System.out.println("Breaked "+ i);
            if(i==5) break label; // This brings you to the point after the labeled loop
		}}
        
        System.out.println("Not Breaked");
    } while (false); // This is not really a loop: it goes through only once
    System.out.println("Do stuff");
    return;
}

public static void doSmthg1(){
    int a=1;
    int b=1;
    label:
    do { // Labeled dummy loop
         //if is given has an example, it can be any thing else
for(int j=0;j<100;j++	){
		for(int i=0;i<10;i++){
            System.out.println("Breaked 1"+ i);
            if(i==5) break label; // This brings you to the point after the labeled loop
		}}
        
        System.out.println("Not Breaked1");
    } while (false); // This is not really a loop: it goes through only once
    System.out.println("Do stuff1");
    return;
}

public static void main(String args[]){
	GotoTest.doSmthg();
GotoTest.doSmthg1();
}

}

