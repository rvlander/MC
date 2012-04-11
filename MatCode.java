import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=matrixFromDouble(80);
double[][] B=matrixFromDouble(4);
A=matrixFromDouble(2);
if(any(eq(B,A))){add(matrixFromDouble(7),matrixFromDouble(6));
B=matrixFromDouble(7);
add(matrixFromDouble(3),matrixFromDouble(2));
};

System.out.println("A=");
printMatrix(A);
System.out.println();
System.out.println("B=");
printMatrix(B);
System.out.println();
}
}
