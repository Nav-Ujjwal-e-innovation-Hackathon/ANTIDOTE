# Generated by Django 3.0.7 on 2020-07-22 06:28

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('basic', '0004_auto_20200721_1121'),
    ]

    operations = [
        migrations.AddField(
            model_name='all_info_form',
            name='complain',
            field=models.TextField(default=''),
        ),
    ]
