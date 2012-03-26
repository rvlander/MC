import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] C=matrixFromDouble(2);
 double[][] fortemp =colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(10));
 for(int posdfo=0;posdfo<fortemp.length;posdfo++){ 
 for(int sdfgsdfgdf=0;sdfgsdfgdf<fortemp[0].length;sdfgsdfgdf++){ 
double[][] i = matrixFromDouble(fortemp[posdfo][sdfgsdfgdf]);
C=add(C,matrixFromDouble(2));
}
}
;

System.out.println("C=");
printMatrix(C);
System.out.println();
}
}
