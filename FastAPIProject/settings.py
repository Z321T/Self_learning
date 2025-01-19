# Description: fastapi配置文件

TORTOISE_ORM = {
    'connections': {
            'default': {
                'engine': 'tortoise.backends.mysql',
                'credentials': {
                    'host': 'localhost',
                    'port': '3306',
                    'user': 'root',
                    'password': 'root',
                    'database': 'fastapi',
                    'charset': 'utf8mb4',
                }
            }
        },
    'apps': {
            'models':{
                'models': ['apps.app05.models', 'aerich.models'],
                'default_connection': 'default',
            }
        },
    'use_tortoise_orm': True,
    'timezone': 'Asia/Shanghai',
}


