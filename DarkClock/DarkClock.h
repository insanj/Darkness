#import <UIKit/UIKit.h>


@interface TableViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>
@property(readonly, nonatomic) UIBarButtonItem *addButton;

-(void)viewWillAppear:(BOOL)arg1;
@end

@interface AlarmView : UIView
@property(readonly, nonatomic) UISwitch *enabledSwitch;
@property(readonly, nonatomic) UILabel *repeatLabel;
@property(readonly, nonatomic) UILabel *nameLabel; // UILabel
@property(readonly, nonatomic) UILabel *timeLabel; // DigitalClockLabel
@property(nonatomic) int style;
@end

@interface AlarmTableViewCell : UITableViewCell
-(void)internalSetBackgroundColor:(id)arg1;
@end

@interface AnalogClockView : UIView {
    UIImage *_backgroundImage;
    UIImage *_backgroundEveningImage;
}
@end

@interface WorldClockTableViewCell : UITableViewCell
+(float)defaultHeight;
-(void)timeDidChangeForClockCell:(id)arg1;
-(void)setEditing:(_Bool)arg1 animated:(_Bool)arg2;
-(void)setStyle:(long long)arg1 animated:(_Bool)arg2;
-(void)stop;
-(void)start;
-(void)layoutSubviews;
-(void)dealloc;
-(id)init;
@end

@interface WorldClockCellView : UIView
@property(readonly, nonatomic) UILabel *combinedLabel; 
@property(readonly, nonatomic) UILabel *nameLabel;
@property(readonly, nonatomic) UILabel *digitalClock; // DigitalClockLabel
@property(readonly, nonatomic) AnalogClockView *analogClock;
@property(nonatomic) int style; // @synthesize style=_style;

-(id)initWithFrame:(struct CGRect)arg1;
-(void)didMoveToSuperview;
-(void)setStyle:(int)arg1 animated:(BOOL)arg2;
@end

@interface UITableViewIndex : UIControl
@property(retain) UIColor *indexBackgroundColor;
@property(retain) UIColor *indexColor;
@property(retain) UIColor *indexTrackingBackgroundColor;
@end

@interface AddClockViewController : UITableViewController <UISearchBarDelegate>{
    UILabel *_noResultsFoundLabel;
}

@property(readonly, nonatomic) id *searchField; // ClockSearchField, UISearchBar?
-(void)searchBar:(id)arg1 textDidChange:(id)arg2;
-(void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
-(id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
-(long long)tableView:(id)arg1 sectionForSectionIndexTitle:(id)arg2 atIndex:(long long)arg3;
-(long long)numberOfSectionsInTableView:(id)arg1;
-(long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
-(id)tableView:(id)arg1 titleForHeaderInSection:(long long)arg2;
-(id)sectionIndexTitlesForTableView:(id)arg1;
-(void)prepopulateSuggestions;
-(void)_showNoResultsFound:(_Bool)arg1;
-(void)_dismiss;
-(void)dealloc;
-(void)viewDidLoad;
-(id)init;
@end

@interface StopwatchTimeView : UIView { // TimeView
    UILabel *_currentLapTimeLabel;
}

@property(nonatomic) double currentLapTime; 
+(double)defaultHeight;
-(_Bool)showSubseconds;
-(CGSize)sizeThatFits:(CGSize)arg1;
-(void)layoutSubviews;
-(void)_layoutWithSize:(CGSize)arg1 maxY:(double *)arg2;
-(void)handleLocaleChange;
-(void)_updateCurrentLapTime;
-(id)init;
-(void)configureBackground;
-(void)configureTimeLabel;
@end


@interface MTStopwatchControlsView : UIView{
    //MTStopwatchController *_controller;
    UIView *_buttonsBackgroundView;
    UIView *_topKeylineView;
    UIView *_bottomKeylineView;
   	StopwatchTimeView *_timeView;
}

//@property(readonly, nonatomic) StopwatchTimeView *timeView;

+(double)defaultHeight;
+(double)timeViewHeight;
-(void)layoutSubviews;
-(void)handleLocaleChange;
-(void)_configureAndAddButton:(id)arg1;
-(void)dealloc;
-(id)initWithTarget:(id)arg1;
@end

@interface MTCircleButton : UIButton
@property(readonly, nonatomic) unsigned long long size;
-(void)setColor:(unsigned long long)arg1 forState:(unsigned long long)arg2; // border color
-(id)initWithSize:(unsigned long long)arg1;
@end

@interface StopWatchViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>{
    MTStopwatchControlsView *_lapControls;
	UITableView *_lapTimeTable;
}
@end
