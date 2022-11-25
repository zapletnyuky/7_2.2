#include "Header.h"
#import <XCTest/XCTest.h>

@interface teest : XCTestCase

@end

@implementation teest

- (void)testLab {
    int count = 0;
    int result, rowNo;
    const int k = 4;
    const int n = 4;
    int a[k][n] ={
        {1, 5, 6, 10},
        {4, 12, 18, 9},
        {3, -2, 7, 0},
        {-3, 4, 6, 7}
    };
    int* pa[4] = { a[0], a[1], a[2], a[3]};
    MaxMin(a, k, n, 0, 0);
    result = count;
    
    XCTAssertNotEqual(12, result);
    
}

@end
