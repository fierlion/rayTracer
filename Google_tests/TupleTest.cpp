//
// Created by Allan, Ray on 12/24/21.
//

#include "gtest/gtest.h"
#include "../Tuples_lib/Tuple.h"
#include "../Tuples_lib/Point.h"
#include "../Tuples_lib/Vector.h"
#include <math.h>

TEST(TupleTestSuite, ExamplePointTuple){ // tuple(4.3, -4.2, 3.1, 1.0) is a point
    Tuple pointTuple(4.3, -4.2, 3.1, POINT_FLOAT);

    EXPECT_EQ(pointTuple.getW(), 1.0);
    EXPECT_TRUE(pointTuple.isPoint());
    EXPECT_FALSE(pointTuple.isVector());
}

TEST(TupleTestSuite, ExampleVectorTuple){ // tuple(4.3, -4.2, 3.1, 0.0) is a vector
    Tuple vectorTuple(4.3, -4.2, 3.1, VECTOR_FLOAT);

    EXPECT_EQ(vectorTuple.getW(), 0.0);
    EXPECT_TRUE(vectorTuple.isVector());
    EXPECT_FALSE(vectorTuple.isPoint());
}

TEST(TupleTestSuite, EmptyTuple){ // tuple() is a vector
    Tuple emptyTuple;

    EXPECT_EQ(emptyTuple.getW(), VECTOR_FLOAT);
    EXPECT_TRUE(emptyTuple.isVector());
    EXPECT_FALSE(emptyTuple.isPoint());
}

TEST(TupleTestSuite, EqualPoints){
    Tuple testPointA(4.3, -4.2, 3.1, POINT_FLOAT);
    Tuple testPointB(4.3, -4.2, 3.1, POINT_FLOAT);
    Tuple testPointC(4.3, -4.1, 3.1, POINT_FLOAT);

    EXPECT_TRUE(testPointA == testPointB);
    EXPECT_FALSE(testPointB == testPointC);
}

TEST(TupleTestSuite, ExamplePoint){
    Point testPoint(4.3, -4.2, 3.1);

    EXPECT_EQ(testPoint.getW(), POINT_FLOAT);
    EXPECT_TRUE(testPoint.isPoint());
}

TEST(TupleTestSuite, EmptyPoint){
    Point emptyPoint;

    EXPECT_EQ(emptyPoint.getW(), POINT_FLOAT);
    EXPECT_TRUE(emptyPoint.isPoint());
}

TEST(TupleTestSuite, TuplePointEqual){
    Point testPoint(4.3, -4.2, 3.1);
    Tuple testTuple(4.3, -4.2, 3.1, POINT_FLOAT);

    EXPECT_TRUE(testPoint == testTuple);
}

TEST(TupleTestSuite, ExampleVector){
    Vector testVector(4.3, -4.2, 3.1);

    EXPECT_EQ(testVector.getW(), VECTOR_FLOAT);
    EXPECT_TRUE(testVector.isVector());
}

TEST(TupleTestSuite, EmptyVector){
    Vector emptyVector;

    EXPECT_EQ(emptyVector.getW(), VECTOR_FLOAT);
    EXPECT_TRUE(emptyVector.isVector());
}

TEST(TupleTestSuite, TupleVectorEqual){
    Vector testVector(4.3, -4.2, 3.1);
    Tuple testTuple(4.3, -4.2, 3.1, VECTOR_FLOAT);

    EXPECT_TRUE(testVector == testTuple);
}

TEST(TupleTestSuite, TupleAddition){
    Tuple testTupleA(1.0, 1.0, 1.0, VECTOR_FLOAT);
    Tuple testTupleB(1.0, 1.0, 1.0, VECTOR_FLOAT);
    Tuple expectedTuple(2.0, 2.0, 2.0, VECTOR_FLOAT);
    Tuple resultTuple = testTupleA + testTupleB;
    Vector resultVector = Vector(2.0, 2.0, 2.0);

    EXPECT_TRUE(expectedTuple == resultTuple);
    EXPECT_TRUE(expectedTuple == static_cast<const Tuple>(resultVector));
}

TEST(TupleTestSuite, TupleSubtraction){
    Tuple testTupleA(1.0, 1.0, 1.0, VECTOR_FLOAT);
    Tuple testTupleB(1.0, 1.0, 1.0, VECTOR_FLOAT);
    Tuple expectedTuple(0.0, 0.0, 0.0, VECTOR_FLOAT);
    Tuple resultTuple = testTupleA - testTupleB;
    Vector resultVector = Vector(0.0, 0.0, 0.0);

    EXPECT_TRUE(expectedTuple == resultTuple);
    EXPECT_TRUE(expectedTuple == static_cast<const Tuple>(resultVector));
}


TEST(TupleTestSuite, PointPointSubtraction){
    Point testPointA(1.0, 1.0, 1.0);
    Point testPointB(1.0, 1.0, 1.0);
    Vector expectedVector(0.0, 0.0, 0.0);
    Vector falseResultVector(-1.0, 0.0, 0.0);
    Vector resultVector = testPointA - testPointB;

    EXPECT_TRUE(expectedVector == resultVector);
    EXPECT_FALSE(expectedVector == falseResultVector);
}

TEST(TupleTestSuite, PointVectorSubtraction){
    Point testPoint(1.0, 1.0, 1.0);
    Vector testVector(1.0, 1.0, 1.0);
    Point expectedPoint(0.0, 0.0, 0.0);
    Point falseResultPoint(-1.0, 0.0, 0.0);
    Point resultPoint = testPoint - testVector;

    EXPECT_TRUE(expectedPoint == resultPoint);
    EXPECT_FALSE(expectedPoint == falseResultPoint);
}

TEST(TupleTestSuite, VectorVectorSubtraction){
    Vector testVectorA(1.0, 1.0, 1.0);
    Vector testVectorB(1.0, 1.0, 1.0);
    Vector expectedVector(0.0, 0.0, 0.0);
    Vector falseResultVector(-1.0, 0.0, 0.0);
    Vector resultVector = testVectorA - testVectorB;

    EXPECT_TRUE(expectedVector == resultVector);
    EXPECT_FALSE(expectedVector == falseResultVector);
}

TEST(TupleTestSuite, Negation){
    Point testPoint(1.0, 1.0, 1.0);
    Vector testVector(1.0, 1.0, 1.0);
    Tuple testTuple(1.0, 1.0, 1.0, POINT_FLOAT);

    Point expectedPoint(-1.0, -1.0, -1.0);
    Vector expectedVector(-1.0, -1.0, -1.0);
    Tuple expectedTuple(-1.0, -1.0, -1.0, POINT_FLOAT);

    EXPECT_TRUE(-testPoint == expectedPoint);
    EXPECT_TRUE(-testVector == expectedVector);
    EXPECT_TRUE(-testTuple == expectedTuple);
}

TEST(TupleTestSuite, ScalarMultiplication){
    Point testPoint(2.0, 2.0, 2.0);
    Vector testVector(2.0, 2.0, 2.0);
    Tuple testTuple(2.0, 2.0, 2.0, POINT_FLOAT);

    Point expectedPoint(4.0, 4.0, 4.0);
    Vector expectedVector(4.0, 4.0, 4.0);
    Tuple expectedTuple(4.0, 4.0, 4.0, POINT_FLOAT);

    float scalar = 2.0;

    EXPECT_TRUE((testPoint * scalar) == expectedPoint);
    EXPECT_TRUE((testVector * scalar) == expectedVector);
    EXPECT_TRUE((testTuple * scalar) == expectedTuple);

}

TEST(TupleTestSuite, ScalarDivision){
    Point testPoint(2.0, 2.0, 2.0);
    Vector testVector(2.0, 2.0, 2.0);
    Tuple testTuple(2.0, 2.0, 2.0, POINT_FLOAT);

    Point expectedPoint(1.0, 1.0, 1.0);
    Vector expectedVector(1.0, 1.0, 1.0);
    Tuple expectedTuple(1.0, 1.0, 1.0, POINT_FLOAT);

    float scalar = 2.0;

    EXPECT_TRUE((testPoint / scalar) == expectedPoint);
    EXPECT_TRUE((testVector / scalar) == expectedVector);
    EXPECT_TRUE((testTuple / scalar) == expectedTuple);
}

TEST(TupleTestSuite, Magnitude) {
    Vector testVectorA(1.0, 0.0, 0.0);
    Vector testVectorB(0.0, 1.0, 0.0);
    Vector testVectorC(0.0, 0.0, 1.0);
    Vector testVectorD(1.0, 2.0, 3.0);
    Vector testVectorE(-1.0, -2.0, -3.0);
    float unitVectorMagnitude = 1.0;
    float squareRootMagnitude = sqrt(14.0);

    EXPECT_EQ(testVectorA.magnitude(), unitVectorMagnitude);
    EXPECT_EQ(testVectorB.magnitude(), unitVectorMagnitude);
    EXPECT_EQ(testVectorC.magnitude(), unitVectorMagnitude);
    EXPECT_EQ(testVectorD.magnitude(), squareRootMagnitude);
    EXPECT_EQ(testVectorE.magnitude(), squareRootMagnitude);
}

TEST(TupleTestSuite, Normalization) {
    Vector testVectorA(4.0, 0.0, 0.0);
    Vector testVectorB(1.0, 2.0, 3.0);
    float unitVectorMagnitude = 1.0;
    Vector expectedVectorA(1.0, 0.0, 0.0);
    Vector expectedVectorB((1/sqrt(14)), (2/sqrt(14)), (3/sqrt(14)));

    EXPECT_TRUE(testVectorA.normalize() == expectedVectorA);
    EXPECT_TRUE(testVectorB.normalize() == expectedVectorB);

    EXPECT_EQ(expectedVectorA.magnitude(), unitVectorMagnitude);
    EXPECT_EQ(expectedVectorB.magnitude(), unitVectorMagnitude);
}

TEST(TupleTestSuite, DotProduct) {
    Vector testVectorA(1.0, 2.0, 3.0);
    Vector testVectorB(2.0, 3.0, 4.0);

    EXPECT_EQ(testVectorA.dotProduct(testVectorB), 20.0);
}

TEST(TupleTestSuite, CrossProduct) {
    Vector testVectorA(1.0, 2.0, 3.0);
    Vector testVectorB(2.0, 3.0, 4.0);
    Vector expectedVectorAB(-1.0, 2.0, -1.0);
    Vector expectedVectorBA(1.0, -2.0, 1.0);

    EXPECT_TRUE(testVectorA.crossProduct(testVectorB) == expectedVectorAB);
    EXPECT_TRUE(testVectorB.crossProduct(testVectorA) == expectedVectorBA);
}
