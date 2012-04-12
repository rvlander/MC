import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=funqui(null,new double[][][]{colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(5)),colon(matrixFromDouble(2),matrixFromDouble(1),matrixFromDouble(6)),colon(matrixFromDouble(3),matrixFromDouble(1),matrixFromDouble(7))});

System.out.println("A=");
printMatrix(A);
System.out.println();
}
public static double[][] funqui(MCJOutputArg[] oargs,double[][][] iargs) throws Exception{
double[][] A = iargs[0];
double[][] E = iargs[1];
double[][] C = iargs[2];
double[][] B= new double[0][0];
B=add(add(A,E),C);

if(oargs !=null){
if(oargs.length>0)oargs[0].val=B;
}
return B;
}

}
