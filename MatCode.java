import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=matrixFromDouble(80);
while(any(gt(A,matrixFromDouble(0)))){A=minus(A,matrixFromDouble(1));
};

System.out.println("A=");
printMatrix(A);
System.out.println();
}
}
