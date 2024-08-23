from typing import List, Dict, Tuple
from datetime import datetime
from collections import defaultdict

def analyze_engagement(user_interactions: List[Tuple[int, str, datetime]]) -> Dict[int, Dict[str, Dict[str, int]]]:
    engagement_summary = defaultdict(lambda: {'total': defaultdict(int), 'monthly_interactions': defaultdict(lambda: defaultdict(int))})

    for user_id, interaction_type, timestamp in user_interactions:
        # Update total interactions
        engagement_summary[user_id]['total'][interaction_type] += 1
        
        # Format the timestamp to 'YYYY-MM' for monthly grouping
        month_key = timestamp.strftime('%Y-%m')
        
        # Update monthly interactions
        engagement_summary[user_id]['monthly_interactions'][month_key][interaction_type] += 1

    # Convert defaultdicts to regular dicts before returning
    return {user_id: {
                'total': dict(user_data['total']),
                'monthly_interactions': {month: dict(interactions) for month, interactions in user_data['monthly_interactions'].items()}
            } for user_id, user_data in engagement_summary.items()}

# Example usage
from datetime import datetime

interactions = [
    (1, 'like', datetime(2024, 7, 1, 12, 0)),
    (1, 'comment', datetime(2024, 7, 15, 15, 0)),
    (1, 'like', datetime(2024, 8, 1, 10, 0)),
    (2, 'share', datetime(2024, 7, 10, 11, 0)),
    (2, 'comment', datetime(2024, 8, 5, 14, 0)),
]

print(analyze_engagement(interactions))
