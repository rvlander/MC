import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
MCJOutputArg[] oa = new MCJOutputArg[2];
oa[0]= new MCJOutputArg();
double[][] A;
oa[1]= new MCJOutputArg();
double[][] B;
size(oa,new double[][][]{colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(5))});
A=oa[0].val;
B=oa[1].val;

System.out.println("A=");
printMatrix(A);
System.out.println();
System.out.println("B=");
printMatrix(B);
System.out.println();
}
}
