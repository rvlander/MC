import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=horzcat(colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(10)),matrixFromDouble(2));

System.out.println("A=");
printMatrix(A);
System.out.println();
}
}
