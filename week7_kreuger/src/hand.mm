//
//  hand.m
//  CoreMLHand
//
//  Created by lingdong on 10/19/21.
//  based on https://github.com/pierdr/ofxiosfacetracking
//       and https://github.com/pambudi02/objc_handgesture

#include "hand.h"

@implementation Hand

-(NSArray*)detect:(CGImageRef)image{

  VNDetectHumanHandPoseRequest *req = [[VNDetectHumanHandPoseRequest new] autorelease];
  NSDictionary *d = [[[NSDictionary alloc] init] autorelease];
  VNImageRequestHandler *handler = [[[VNImageRequestHandler alloc] initWithCGImage:image options:d] autorelease];

  [handler performRequests:@[req] error:nil];

  return req.results;
}
@end

HAND::HAND(){
  tracker = [[Hand alloc] init];
}

void HAND::detect(ofPixels pix)
{
  CGImageRef image = CGImageRefFromOfPixels(pix,(int)pix.getWidth(),(int)pix.getHeight(),(int)pix.getNumChannels());
  NSArray* arr = [tracker detect:image];
  NSError *err;
//    VNHumanHandPoseObservation *observation =(VNHumanHandPoseObservation*) arr.firstObject;
  for(VNHumanHandPoseObservation *observation in arr){
      NSDictionary <VNHumanHandPoseObservationJointName, VNRecognizedPoint *> *thumbPts = [observation recognizedPointsForJointsGroupName:VNHumanHandPoseObservationJointsGroupNameThumb error:&err];
      NSDictionary <VNHumanHandPoseObservationJointName, VNRecognizedPoint *> *indexPts = [observation recognizedPointsForJointsGroupName:VNHumanHandPoseObservationJointsGroupNameIndexFinger error:&err];
      VNRecognizedPoint *thumbTip = [thumbPts objectForKey:VNHumanHandPoseObservationJointNameThumbTip];
      VNRecognizedPoint *indexTip = [indexPts objectForKey:VNHumanHandPoseObservationJointNameIndexTip];
      
    thumb.x = thumbTip.location.x*pix.getWidth();
    thumb.y = (1-thumbTip.location.y)*pix.getHeight();
    index.x = indexTip.location.x*pix.getWidth();
    index.y = (1-indexTip.location.y)*pix.getHeight();
    break;
  }
}

CGImageRef HAND::CGImageRefFromOfPixels( ofPixels & img, int width, int height, int numberOfComponents ){
  
  int bitsPerColorComponent = 8;
  int rawImageDataLength = width * height * numberOfComponents;
  BOOL interpolateAndSmoothPixels = NO;
  CGBitmapInfo bitmapInfo = kCGBitmapByteOrderDefault;
  CGColorRenderingIntent renderingIntent = kCGRenderingIntentDefault;
  CGDataProviderRef dataProviderRef;
  CGColorSpaceRef colorSpaceRef;
  CGImageRef imageRef;
  
  GLubyte *rawImageDataBuffer =  (unsigned char*)(img.getData());
  dataProviderRef = CGDataProviderCreateWithData(NULL,  rawImageDataBuffer, rawImageDataLength, nil);
  if(numberOfComponents>1)
  {
    colorSpaceRef = CGColorSpaceCreateDeviceRGB();
  }
  else
  {
    colorSpaceRef = CGColorSpaceCreateDeviceGray();
  }
  imageRef = CGImageCreate(width, height, bitsPerColorComponent, bitsPerColorComponent * numberOfComponents, width * numberOfComponents, colorSpaceRef, bitmapInfo, dataProviderRef, NULL, interpolateAndSmoothPixels, renderingIntent);
  
  return imageRef;
}
