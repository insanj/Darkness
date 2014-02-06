#import "DarkClock.h"

/*%hook UIView

-(UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event{
	UIView *o = %orig();
	if(o != nil){
		NSLog(@"[DarkClock] DEBUG, hit: %@, super:%@, sub:%@", o, o.superview, o.subviews);
	}

	return o;
}

%end*/


%ctor{
    [UITabBar appearance].barStyle = UIBarStyleBlack;
    [UINavigationBar appearance].barStyle = UIBarStyleBlack;
}

%hook TableViewController

-(void)viewWillAppear:(BOOL)arg1{
	%orig();
	MSHookIvar<UITableView *>(self, "_tableView").backgroundColor = [UIColor blackColor];
}

%end

%hook AlarmTableViewCell

-(void)internalSetBackgroundColor:(UIColor *)arg1{
	%orig([UIColor blackColor]);

	if([arg1 isEqual:[UIColor whiteColor]]){
		AlarmView *alarmView = [self.contentView.subviews firstObject];
		for(UIView *v in alarmView.subviews)
			if([v isKindOfClass:[UILabel class]])
				((UILabel *)v).textColor = [UIColor whiteColor];
	}
}

-(void)layoutSubviews{
	%orig();

	AlarmView *alarmView = [self.contentView.subviews firstObject];
	for(UIView *v in alarmView.subviews)
		if([v isKindOfClass:[UISwitch class]])
			((UISwitch *)v).onTintColor = [UIColor redColor];
}

%end


%hook WorldClockCellView

-(id)initWithFrame:(CGRect)arg1{
	WorldClockCellView *view = (WorldClockCellView *) %orig();
	view.backgroundColor = [UIColor blackColor];
	return view;
}

-(void)layoutSubviews{
	%orig();

	for(UIView *v in self.subviews){
		if([v isKindOfClass:[UILabel class]])
			((UILabel *)v).textColor = [UIColor whiteColor];
		//if([v isKindOfClass:[AnalogClockView class]])
	}
}

%end

%hook AddClockViewController

-(id)init{
	AddClockViewController *view = (AddClockViewController *) %orig();
	view.tableView.backgroundColor = [UIColor blackColor];

	for(UIView *v in view.tableView.subviews){
		if([v isKindOfClass:[%c(UITableViewIndex) class]]){
			((UITableViewIndex *)v).indexBackgroundColor = [UIColor colorWithWhite:0.0 alpha:0.25];
			((UITableViewIndex *)v).indexTrackingBackgroundColor = [UIColor colorWithWhite:0.0 alpha:0.25];
		}
	}

	return view;
}

-(id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2{
	UITableViewCell *cell = (UITableViewCell *) %orig();
	cell.backgroundColor = [UIColor blackColor];
	cell.textLabel.textColor = [UIColor whiteColor];
	return cell;
}

%end

%hook UIKBRenderConfig

-(BOOL)lightKeyboard{
	return NO;
}

%end